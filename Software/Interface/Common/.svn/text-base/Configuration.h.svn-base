/*
 * Configuration.h
 *
 * Provides an interface for reading from and writing to
 * a configuration file.
 *
 * Created by Camden Lopez on 1/12/11
 * Copyright © 2010-2011 Oregon State University Robotics Club */

#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QMap>

class Configuration : public QMap<QString, QString>
{
public:
	explicit Configuration(const QString & filePath = QString());
	void setFilePath(const QString & filePath);
	void updateFromFile();
	void writeToFile();

private:
	QString path;
	void processFileLine(const QString & line);
};

#endif // CONFIGURATION_H
