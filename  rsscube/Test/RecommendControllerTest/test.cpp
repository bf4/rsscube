// 2009-07-09 裴小星 编写测试

#include "test.h"
#include "../../RssCube/control/DatabaseController.h"

Test::Test()
{
    DatabaseController databaseController = DatabaseController::getInstance();
    databaseController.connect("../../RssCube/rss_cube.db");
}

void Test::getSystemRecommendChannels_test()
{
    Channel channel = RecommendController::getInstance().getSystemRecommendChannels().at(0);
    QCOMPARE(channel.getName(), QString("system"));
}

void Test::getUserRecommendChannels_test()
{
    Channel channel = RecommendController::getInstance().getUserRecommendChannels().at(0);
    QCOMPARE(channel.getName(), QString("user"));
}

void Test::setRecommendChannels_test()
{
    QVector<int> v;
    v << 3;
    RecommendController::getInstance().setRecommendChannels(v);
}

QTEST_MAIN(Test)
