/*
 * VideoWidget.h
 *
 * Displays video and some critical status information.
 *
 * Created by Camden Lopez on 11/14/10
 * Copyright © 2010 Oregon State University Robotics Club
 */

#ifndef VIDEOWIDGET_H
#define VIDEOWIDGET_H

#include "ui_VideoWidget.h"

class VideoWidget : public QWidget, private Ui::VideoWidget
{
    Q_OBJECT

public:
    explicit VideoWidget(QWidget *parent = 0);
};

#endif // VIDEOWIDGET_H
