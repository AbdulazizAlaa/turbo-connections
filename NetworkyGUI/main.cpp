#include "networkwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NetworkWindow w;
    w.show();

    return a.exec();
}
