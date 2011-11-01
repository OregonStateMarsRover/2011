/*
 * Author: Taj Morton
 * Date: December 30, 2009
 * Purpose: Class for using UNIX serial ports.
 *
 * Copyright (c) 2009 OSURC.
 */

using namespace std;

#include <QString>
#include <QStringList>
#include <termios.h>

//! An interface for using UNIX serial ports
class SerialDevice {
	public:
		//! Parity modes for serial ports
		enum ParityMode { NoParity, EvenParity, OddParity };
		
		//! Creates and opens serial port
		/*!
		 Opens the given serial port with the given baud rate.
		 Port is configured for 8 bits, no parity, one stop bit.
		 \param filename Device filename
		 \param baud Baud rate
		 */
                SerialDevice(QString filename, unsigned int baud);
		
		//! Constructor
		/*!
		 Creates a serial port device with default settings.
		 You must set the serial port (as well as any other settings
		 you need) before calling open().
		 Default settings are:
		 - 9600 baud
		 - 8 bit mode
		 - 1 stop bit
		 - No Pairty
		 */
		SerialDevice();
		
		//! Cleans up and closes serial port if open.
		~SerialDevice();
		
		//! Opens serial port with current settings.
		/*!
		 \return True if port has been successfully opened and is ready to use. False otherwise.
		 */
		bool openSerial();
		
		//! Closes serial port
		/*!
		 \return True if port was successfully closed, false otherwise.
		 */
		bool closeSerial();
		
		//! Sets number of data bits
		/*! Only valid values are 5 through 8.
		 If this is called while the port is open, it must be
		 closed and reopened before the settings take effect.
		 \param dataBits Number of data bits
		 */
		void setDataBits(char dataBits);
		
		//! Sets number of stop bits
		/*! Only valid values are 1 and 2.
		 If this is called while the port is open, it must be
		 closed and reopened before the settings take effect.
		 \param stopBits Number of stop bits
		 */
		void setStopBits(char stopBits);
		
		//! Sets parity mode of serial port
		/*!
		 If this is called while the port is open, it must be
		 closed and reopened before the settings take effect.
		 \param mode New parity mode
		 */
		void setParityMode(ParityMode mode);
		
		//! Writes data to serial port
		/*!
		 Writes data to serial port.
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
                int writeString(QString data);

                int writeData(QByteArray data);
		
		//! Writes single character to serial port
		/*!
		 \param c Character to write
		 \return True if character successfully written, false otherwise.
		 */
		bool writeChar(char c);
		
		//! Reads data from serial port
		/*!
		 \param buf Buffer to read data into
		 \param maxlen Maximum number of bytes to read.
		 \return Number of bytes read, or negative number on error.
		 */
		int readData(char * buf, int maxlen);
		
		//! Reads a line of data from serial port
		/*!
		 Attempts to read an entire line out of the buffer, or returns
		 -1 if there isn't a complete line in the buffer. The string is
		 NOT null terminated, and does NOT contain the line ending.
		 \param buf Buffer to read data into
		 \param maxlen Maximum number of bytes to read
		 \return Number of bytes read
		 */
		int readLine(char * buf, int maxlen);
		
		//! Gets number of bytes in receive buffer
		/*!
		 \return number of bytes that can be read successfully
		 */
		int numBytesAvailable();
		
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

                static QStringList getSerialPortNames();
	
	private:
		int fd;
		unsigned int baud, stopBits, dataBits;
                QString filename;
		ParityMode parity;
		
		// keep a copy of the origional configuration so we can restore it on exit and not corrupt anything
		struct termios orig_options;
		
		//! Sets default settings for serial ports
		/*!
		 These are:
		 - 9600 baud
		 - 8 bit mode
		 - 1 stop bit
		 - No Pairty
		 */
		void setDefaults();
};
