#ifndef TEST_H
#define TEST_H

#include <QtTest/QtTest>

#include "../../RssCube/entity/Channel.h"

class Test : public QObject
{
    Q_OBJECT

public:
    Test();

private slots:
    void getChannel_test();
};

#endif // TEST_H
