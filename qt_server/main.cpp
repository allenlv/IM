
#include "qt_server.h"

#include <QtGui>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qt_server w;
    w.show();
    return a.exec();
}
