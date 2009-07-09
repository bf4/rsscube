#ifndef TEST_H
#define TEST_H

#include <QtTest/QtTest>

#include "../../RssCube/control/SearchController.h"

class Test : public QObject
{
    Q_OBJECT

public:
    Test();

private slots:
    void localSearch_test();
};

#endif // TEST_H
