#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    qputenv("QT_MEDIA_BACKEND", "windows");
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
