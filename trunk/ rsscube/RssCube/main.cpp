#include <QtGui/QApplication>
#include "boundary/MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow m;
    m.show();
    return a.exec();
}
