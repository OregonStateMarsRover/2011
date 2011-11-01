/*
 * Author: Taj Morton
 * Date: December 30, 2009
 * Purpose: Class for communicating with USB devices.
 *
 * Copyright (c) 2009-2010 OSURC.
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>

#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>

#include <linux/types.h>
#include <linux/ioctl.h>
#include <linux/hidraw.h>

#include "USBDevice.h"

#include <QDebug>

USBDevice::USBDevice(string filename) {
        this->readFilename = this->writeFilename = filename;
        readFd = writeFd = -1;
	
	openUSB();
}

USBDevice::USBDevice(string readFilename, string writeFilename) {
    this->writeFilename = writeFilename;
    this->readFilename = readFilename;

    readFd = writeFd = -1;
    openWriteEndpoint();
    openReadEndpoint();
}

USBDevice::USBDevice(int vendor_id, int product_id, int writeDevNum, int readDevNum) {
	struct hidraw_devinfo info;
	
	vector<string> devices = getHidRawDevices();
        writeFd = readFd = -1;
        int foundMatches = 0;
	
        for (int i=devices.size()-1; i>=0; i--) {
            int oldFoundMatches = foundMatches;
		int f = open(devices[i].c_str(), O_RDWR);
                if (f<1) {
                    qDebug() << "failed to open hid device"<<devices[i].c_str();
			continue; // couldn't open this device
		}
		int n;
		if ((n = ioctl(f, HIDIOCGRAWINFO, &info)) < 0) {
                        qDebug() << "IOCTL failed while getting HID PID/VID:"<<n<<". Are you root?";
		}
		else {
			if (info.vendor==vendor_id && (info.product & 0xFFFF)==(product_id & 0xFFFF)) { // mask off high bits because linux fills info.product with 0xFFFF
                            qDebug() <<"Found Device: "<<devices[i].c_str();

                            if (writeDevNum==readDevNum) { // if read and write devices are the same, just open like normal and be done
                                readFilename = readFilename = devices[i];
                                close(f);
                                openUSB();
                                break;
                            }
                            else {
                                if (writeDevNum<readDevNum) { // use write device before read
                                    if (foundMatches==0) { // this is write device
                                        writeFilename = devices[i];
                                        close(f);
                                        openWriteEndpoint();

                                        foundMatches++;
                                        continue;
                                    }
                                    else { // this is read device
                                        close(f);
                                        readFilename = devices[i];
                                        openReadEndpoint();

                                        foundMatches++;
                                        continue;
                                    }
                                }
                                else { // use read device before write
                                    if (foundMatches==0) { // this is read device
                                        readFilename = devices[i];
                                        close(f);
                                        qDebug() << "closing fd" <<f;
                                        openReadEndpoint();

                                        foundMatches++;
                                        continue;
                                    }
                                    else { // this is write device
                                        writeFilename = devices[i];
                                        close(f);
                                        qDebug() << "closing fd" <<f;
                                        openWriteEndpoint();

                                        foundMatches++;
                                        continue;
                                    }
                                }
                            }
			}
		}
                if (foundMatches==oldFoundMatches) {
                   qDebug() << "closing fd" <<f;
                   close(f);
               }
	}
}

USBDevice::USBDevice() {
        readFd = writeFd = -1;
        this->readFilename = this->writeFilename = "";
}

USBDevice::~USBDevice() {
	closeUSB();
}

vector<string> USBDevice::getHidRawDevices() {
	DIR * dp;
	struct dirent * dirp;
	
	vector<string> files;
	
	if ((dp = opendir("/dev"))==NULL) {
                qDebug() << "Could not open /dev directory";
	}
	while ((dirp = readdir(dp)) != NULL) {
		string name = string(dirp->d_name);
		
                if (name.substr(0,6)=="hidraw") {
			files.push_back("/dev/"+string(dirp->d_name));
                    }
	}
	closedir(dp);
	return files;
}

bool USBDevice::openUSB() {
        if (readFd==-1 && writeFd==-1 && readFilename!="") {
                readFd = writeFd = open(readFilename.c_str(), O_RDWR);
                qDebug() << "opening file" << readFilename.c_str()<<readFd;
                if (readFd<=0) {
                        qDebug() << "Failed to open HID device "<<readFilename.c_str();
			return false;
		}
		else {
                        fcntl(readFd, F_SETFL, 0 | O_NONBLOCK); // set non-blocking
			return true;
		}
	}
	return false;
}

bool USBDevice::openWriteEndpoint() {
    int fd;
    if (writeFd==-1 && writeFilename!="") {
        writeFd = openDevice(writeFilename, true);
        qDebug() << "opening" <<writeFilename.c_str() <<" for writing:"<<writeFd;
        if (writeFd!=-1)
            return true;
        else
            return false;
    }
    else {
        return false;
    }
}

bool USBDevice::openReadEndpoint() {
    if (readFd==-1 && readFilename!="") {
        readFd = openDevice(readFilename, false);
        qDebug() << "opening" <<readFilename.c_str() <<" for reading: "<<readFd;
        if (readFd!=-1)
            return true;
        else
            return false;
    }
    else {
        return false;
    }
}

int USBDevice::openDevice(std::string dev, bool forWriting) {
    int fd;
    if (dev!="") {
        if (forWriting)
            fd = open(dev.c_str(), O_WRONLY);
        else
            fd = open(dev.c_str(), O_RDONLY);

        if (fd<=0) {
            qDebug() << "Failed to open HID device "<<dev.c_str();
            return -1;
        }
        else if (!forWriting) {
            fcntl(fd, F_SETFL, 0 | O_NONBLOCK); // set non-blocking
        }

        return fd;
    }
    else {
        return -1;
    }
}

bool USBDevice::closeUSB() {
        if (readFd!=-1) {
                close(readFd);
                qDebug() << "closing readFd"<<readFd;
	}

        if (writeFd!=-1 && writeFd!=readFd) {
            close(writeFd);
            qDebug() << "closing writeFd"<<readFd;
            return true;
        }
	return false;
}

int USBDevice::writeData(const char * data, int len) {
        if (writeFd!=-1) {
            qDebug() << "trying to write...";
            int ret;
            ret = write(writeFd, data, len);
            qDebug() << "returned" << ret << "writeFd"<<writeFd;
            perror("USB[W]");
            return ret;
        }
	else
            return -1;
}

int USBDevice::writeString(string data) {
	return writeData(data.c_str(), data.length());
}

bool USBDevice::writeChar(char c) {
	if (writeData(&c, 1)==1)
		return true;
	else
		return false;
}

int USBDevice::readData(char * buf, int maxlen) {
        if (readFd!=-1)
                return read(readFd, buf, maxlen);
	else
		return -1;
}

int USBDevice::getFileDescriptor() {
        return readFd;
}

bool USBDevice::deviceOpened() {
        return readFd!=-1;
}

