#include <QtGui/QApplication>
#include <QtGui/QMainWindow>
#include <QtGui/QVBoxLayout>
#include "VideoFeed.cpp"
#include "VideoForm.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("rover");
    QMainWindow window;
    VideoForm w(&window);

    /*QVBoxLayout * mainLayout = new QVBoxLayout();
    mainLayout->addWidget(&w,1);
    window.setLayout(mainLayout);
*/
    window.setCentralWidget(&w);
    window.show();

    return a.exec();
}
