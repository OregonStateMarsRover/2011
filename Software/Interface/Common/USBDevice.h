/*
 * Author: Taj Morton
 * Date: December 30, 2009
 * Purpose: Class for communicating with USB devices.
 *
 * Copyright (c) 2009-2010 OSURC.
 */

#ifndef HAVE_USBDEVICE_H
#define HAVE_USBDEVICE_H
using namespace std;

#include <string>
#include <vector>
#include <termios.h>

//! An interface for communicating with rawhid USB devices
class USBDevice {
	public:
		//! Creates and opens a RAWHID device
		/*!
		 \param filename RAWHID device filename
		 */
                USBDevice(string filename);

                USBDevice(string readFilename, string writeFilename);
		
		//! Creates and opens a RAWHID device
		/*!
		 \param vendor_id Vendor ID of device to open
		 \param product_id Product ID of device to open
		 */
                USBDevice(int vendor_id, int product_id, int writeDevNum = 1, int readDevNum = 1);
		
		//! Constructor
		/*!
		 Creates an unopened rawhid device
		 */
		USBDevice();
		
		//! Cleans up and closes USB device if open
		~USBDevice();
		
		//! Opens USB devie
		/*!
		 \return True if device has been successfully opened and is ready to use. False otherwise.
		 */
		bool openUSB();

                bool openWriteEndpoint();
                bool openReadEndpoint();
		
		//! Closes USB device
		/*!
		 \return True if device was successfully closed, false otherwise.
		 */
		bool closeUSB();
		
		//! Writes data to USB device
		/*!
		 \param data Data to write
		 \param len Number of bytes to write (and read out of data).
		 \return Number of bytes written, or negative number on error.
		 */
		int writeData(const char * data, int len);
		
		//! Writes C++ string to serial port
		/*!
		 \param data String to write.
		 \return Number of bytes written, or negative number on error.
		 */
		int writeString(string data);
		
		//! Writes single character to USB device
		/*!
		 \param c Character to write
		 \return True if character successfully written, false otherwise.
		 */
		bool writeChar(char c);
		
		//! Reads data from USB device
		/*!
		 \param buf Buffer to read data into
		 \param maxlen Maximum number of bytes to read.
		 \return Number of bytes read, or negative number on error.
		 */
		int readData(char * buf, int maxlen);
		
		//! Returns the value of the file descriptor
		/*!
		 This can be used for configuring serial ports for strange
		 and unsupported settings.
		 WARNING: BE VERY CAREFUL WITH THE FILE DESCRIPTOR. It's
		 very easy to blow things up.
		 \return File descriptor, suitable for use with such functions
		 as fcntl() and tcsetattr().
		 */
		int getFileDescriptor();
		
		//! Returns true if device is open
		/*!
		 \return Returns true if USB device is open and ready to be used, false otherwise
		 */
		bool deviceOpened();
	
	private:
                //int fd;
                int writeFd, readFd;
                string readFilename, writeFilename;

                int openDevice(std::string dev, bool forWriting);
		
		//! Searches /dev directory for all /dev/hidraw* files
		/*!
		 \return Returns list of full paths to raw HID devices
		 */
		vector<string> getHidRawDevices();
		
};
#endif
