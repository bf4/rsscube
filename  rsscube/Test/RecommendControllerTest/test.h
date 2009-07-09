#ifndef TEST_H
#define TEST_H

#include <QtTest/QtTest>

#include "../../RssCube/control/RecommendController.h"

class Test : public QObject
{
    Q_OBJECT

public:
    Test();

private slots:
    void getSystemRecommendChannels_test();
    void getUserRecommendChannels_test();
    void setRecommendChannels_test();
};

#endif // TEST_H
