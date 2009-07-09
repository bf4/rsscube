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
    void getAllChannels_test();
    void getChannelByGroupId_test();
    void getSystemRecommendChannels_test();
    void getUserRecommendChannels_test();
    void setRecommendChannels_test();
    void addChannel_test();
    void removeChannel_test();
    void setGroup_test();
    void rename_test();
};

#endif // TEST_H
