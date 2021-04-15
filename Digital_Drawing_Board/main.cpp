#include "mainwindow.h"

#include <QApplication>
#include<QSplashScreen>
#include<QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSplashScreen splash;
    splash.setPixmap(QPixmap("C:/QT_eg/DrawingExample4/loveWhat.jpg"));
    splash.showFullScreen();
    MainWindow w;
    QTimer::singleShot(2500,&splash,SLOT(close()));
    QTimer::singleShot(2500,&w,SLOT(showFullScreen()));

    return a.exec();
}
