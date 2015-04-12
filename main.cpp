#include "mainwindow.h"
#include <QApplication>
#include <QMediaPlayer>

int main(int argc, char *argv[])
{
    QApplication StarStuff(argc, argv);
    MainWindow w;
    w.setWindowTitle("Star Stuff - Main Menu");
    w.show();


    return StarStuff.exec();
}
