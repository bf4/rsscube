#include <QtGui/QApplication>
#include <QTextCodec>
#include "boundary/RssCube.h"

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));

    QApplication a(argc, argv);
    RssCube m;
    m.show();
    return a.exec();
}
