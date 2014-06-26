#include <QApplication>
#include "login.h"

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf8"));
    QApplication::setStyle("cleanlooks");
    QApplication a(argc, argv);

    login w;
    w.setWindowTitle("ClientLogin");


    w.setWindowOpacity(1);
    w.setWindowFlags(Qt::FramelessWindowHint);
    w.setAttribute(Qt::WA_TranslucentBackground);
    w.show();
    w.move(200,100);
    return a.exec();
}
