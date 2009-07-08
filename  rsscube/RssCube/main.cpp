#include <QtGui/QApplication>
#include <QTextCodec>
#include "boundary/MainWindow.h"

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));

    QApplication a(argc, argv);
    MainWindow m;
    m.show();
    return a.exec();
}
