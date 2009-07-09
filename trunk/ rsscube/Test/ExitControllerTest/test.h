#ifndef TEST_H
#define TEST_H

#include <QtTest/QtTest>

#include "../../RssCube/control/ExitController.h"
#include "../../RssCube/control/StartController.h"

class Test : public QObject
{
    Q_OBJECT

private slots:
    void exitBeforeStart_test();
    void exitAfterStart_test();
};

#endif // TEST_H
