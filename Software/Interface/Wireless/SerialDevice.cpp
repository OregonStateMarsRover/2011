/*
 * Author: Taj Morton
 * Date: December 30, 2009
 * Purpose: Class for using UNIX serial ports.
 *
 * Copyright (c) 2009 OSURC.
 * Portions copied from Kyle Vogt's Roboteq Library:
 * http://web.mit.edu/kvogt/www/roboteq.html
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>

#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "SerialDevice.h"

#include <QDebug>
#include <QDir>

SerialDevice::SerialDevice(QString filename, unsigned int baud) {
	setDefaults();
	
	this->baud = baud;
	this->filename = filename;
	
	openSerial();
}

SerialDevice::SerialDevice() {
	setDefaults();
}

SerialDevice::~SerialDevice() {
	closeSerial();
}

bool SerialDevice::openSerial() {
	if (fd!=-1) {
		return true; // already open
	}
	
        fd = open(qPrintable(filename), O_RDWR | O_NOCTTY  /*| O_NDELAY*/);
	
	if (fd!=-1) { // successfully opened
		tcgetattr(fd, &orig_options); // make a copy so we can restore on exit and not corrupt anything
		
		struct termios options;
		tcgetattr(fd, &options);
		
		switch(baud) {
			case 4800:
				cfsetispeed(&options, B4800);
				cfsetospeed(&options, B4800);
				break;
			case 9600:
				cfsetispeed(&options, B9600);
				cfsetospeed(&options, B9600);
				break;
			case 38400:
				cfsetispeed(&options, B38400);
				cfsetospeed(&options, B38400);
				break;
			case 57600:
				cfsetispeed(&options, B57600);
				cfsetospeed(&options, B57600);
				break;
			case 115200:
				cfsetispeed(&options, B115200);
				cfsetospeed(&options, B115200);
				break;
			default:
                                qWarning() << "Unknown baud rate "<<baud<<". Defaulting to 9600.";
				cfsetispeed(&options, B9600);
				cfsetospeed(&options, B9600);
				break;
		}
		
			options.c_cflag |= (CLOCAL | CREAD); // don't "own" the port. see http://www.easysw.com/~mike/serial/serial.html#3_1_1 for more information about UNIX serial ports
		
		switch (parity) {
			case NoParity:
				options.c_cflag &= ~PARENB; // clear enable parity
				break;
			case EvenParity:
				options.c_cflag |= PARENB; // enable parity
				options.c_cflag &= ~PARODD; // clear odd parity
				break;
			case OddParity:
				options.c_cflag |= PARENB; // enable parity
				options.c_cflag &= ~PARODD; // enable odd parity
				break;
			default:
                                qWarning() << "Unknown parity mode. Defaulting to no parity.";
				options.c_cflag &= ~PARENB; // clear enable parity
		}
		
		switch (stopBits) {
			case 1:
				options.c_cflag &= ~CSTOPB; // clear 2 stop bit option
				break;
			case 2:
				options.c_cflag |= CSTOPB; // set 2 stop bits option
				break;
			
			default:
                                qWarning() << "Invalid number of stop bits ("<<stopBits<<"). Defaulting to 1.";
				options.c_cflag &= ~CSTOPB; // clear 2 stop bit option
		}
		
		options.c_cflag &= ~CSIZE; // clear current databit value
		switch (dataBits) {
			case 5:
				options.c_cflag |= CS5;
				break;
			case 6:
				options.c_cflag |= CS6;
				break;
			case 7:
				options.c_cflag |= CS7;
				break;
			case 8:
				options.c_cflag |= CS8;
				break;
			default:
                                qWarning() << "Invalid number of databits ("<<dataBits<<"). Defaulting to 8.";
				options.c_cflag |= CS8;
		}
		
		options.c_cflag &= ~CRTSCTS; // disable flow control
		
		options.c_lflag &= ~(ICANON | ECHO | ECHOE /*| ISIG*/); // enable raw mode
		
		
		options.c_cc[VMIN] = 0; // no minimum number of characters to read
		options.c_cc[VTIME] = 3; // wait 3/10 os a second for a character before giving up
		
		tcsetattr(fd, TCSANOW, &options); // write new settings
                qDebug() << "Opened serial port "<<qPrintable(filename);
		return true; // everything went well, declare success
	}
	else {
                qDebug() << "Failed to open serial port "<<qPrintable(filename);
		closeSerial();
		return false;
	}
}

bool SerialDevice::closeSerial() {
	if (fd!=-1) { // port is open
		tcdrain(fd); // wait until everything is written
		tcflush(fd, TCIOFLUSH);
		tcsetattr(fd, TCSANOW, &orig_options); // restore origional settings so we don't destroy the port
		
		close(fd);
                qDebug() << "Closed serial port "<<filename;
		fd = -1;
		return true;
	}
	return false; // already cosed
}

void SerialDevice::setDataBits(char dataBits) {
	if (dataBits>=5 && dataBits<=8)
		this->dataBits = dataBits;
	else
                qWarning() << "Invalid databit setting "<<dataBits;
}

void SerialDevice::setStopBits(char stopBits) {
	if (stopBits==1 || stopBits==2)
		this->stopBits = stopBits;
	else
                qWarning() << "Invalid stop bits setting "<<stopBits;
}

void SerialDevice::setParityMode(ParityMode mode) {
	this->parity = mode;
}

int SerialDevice::writeData(const char * data, int len) {
	if (fd!=-1) { // port open
		return  write(fd, data, len);
	}
	else
		return -1;
}

int SerialDevice::writeData(QByteArray data) {
    return writeData(data.data(),data.length());
}

int SerialDevice::writeString(QString data) {
        qDebug() << "Writing "<<data.length()<<" bytes...\n";
        return writeData(qPrintable(data), data.length());
}

bool SerialDevice::writeChar(char c) {
	if (writeData(&c, 1)==1)
		return true;
	else
		return false;
}

int SerialDevice::readData(char * buf, int maxlen) {
	if (fd!=-1) {
		return read(fd, buf, maxlen);
	}
	else
		return -1;
}

int SerialDevice::readLine(char * buf, int maxlen) {
	// TODO: Implement readLine()
	return -1;
}

int SerialDevice::numBytesAvailable() {
	int bytes;
	ioctl(fd, FIONREAD, &bytes);
	return bytes;
}

int SerialDevice::getFileDescriptor() {
	return fd;
}

void SerialDevice::setDefaults() {
	fd = -1; // closed
	baud = 9600;
	stopBits = 1;
	dataBits = 8;
	parity = NoParity;
}

QStringList SerialDevice::getSerialPortNames() {
        QStringList filter;
        filter.append("ttyUSB*");
        QDir dir("/dev");

        QStringList dirs = dir.entryList(filter,QDir::System);
        QStringList serials;

        foreach(QString s, dirs) {
                serials.append(dir.absoluteFilePath(s));
        }

        return serials;
}
