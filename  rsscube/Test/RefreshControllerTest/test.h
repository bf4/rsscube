#ifndef TEST_H
#define TEST_H

#include <QtTest/QtTest>

#include "../../RssCube/control/RefreshController.h"

class Test : public QObject
{
    Q_OBJECT

private slots:
    void test();
};

#endif // TEST_H
