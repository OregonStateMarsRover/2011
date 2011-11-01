/*
 * Configuration.cpp
 *
 * Created by Camden Lopez on 1/12/11
 * Copyright © 2010-2011 Oregon State University Robotics Club */

#include <QDebug>
#include <QFile>
#include <QStringList>

#include "Configuration.h"

Configuration::Configuration(const QString & filePath) :
		path(filePath)
{
	updateFromFile();
}

void Configuration::setFilePath(const QString & filePath)
{
	if (path != filePath) {
		path = filePath;
		updateFromFile();
	}
}

void Configuration::updateFromFile()
{
	QFile file(path);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
		qDebug() << "Failed to open " << path << " for reading";
		return;
	}
	while (!file.atEnd())
		processFileLine(QString(file.readLine()));
	file.close();
}

void Configuration::writeToFile()
{
	QFile file(path);
	if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)) {
		qDebug() << "Failed to open " << path << " for writing";
		return;
	}
	QMap<QString, QString>::const_iterator i;
	for (i = constBegin(); i != constEnd(); i++) {
		qDebug() << "Writing config item with key" << i.key()
				<< "and value" << i.value();
		file.write(i.key().toAscii());
		file.write(QByteArray(" = "));
		file.write(i.value().toAscii());
	}
	file.close();
}

void Configuration::processFileLine(const QString & line)
{
	// Remove any comment and split what's left into key and value
	QStringList elements = line.left(line.indexOf("#")).split("=");
	if (elements.length() >= 2) {
		qDebug() << "Setting config item with key" << elements[0].trimmed()
				<< "to" << elements[1].trimmed();
		insert(elements[0].trimmed(), elements[1].trimmed());
	}
}
