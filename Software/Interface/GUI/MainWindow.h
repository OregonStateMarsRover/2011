/*
 * MainWindow.h
 *
 * The main window for the rover interface application.
 *
 * Created by Camden Lopez on 11/10/10
 * Copyright © 2010-2011 Oregon State University Robotics Club */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QLabel>
#include <QAction>
#include<QLineEdit>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    void createMyMenu();

private:
    QLabel* label1;
    QMenu *bar;
    QMenu *bar1;
    QLineEdit *line;
    QAction* showAct;
    QAction* hideAct;
    QAction* exitAct;
    QAction* copy;
    QAction* cut;
    QAction* paste;

};

#endif // MAINWINDOW_H
