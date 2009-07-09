// 2006-07-08 裴小星 编写测试

#include "test.h"
#include "../../RssCube/control/DatabaseController.h"

Test::Test()
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));

    DatabaseController databaseController = DatabaseController::getInstance();
    databaseController.connect("../../RssCube/rss_cube.db");
}

void Test::getChannel_test()
{
    Channel channel = Channel::getChannel(1);
    QCOMPARE(channel.getId(), 1);
    QCOMPARE(channel.getName(), QString("新浪"));
    QCOMPARE(channel.getUrl(), QString("http://rss.sina.com.cn/news/marquee/ddt.xml"));
}

void Test::getAllChannels_test()
{
    QVector<Channel> channels = Channel::getAllChannels();

    Channel channel = channels.at(0);
    QCOMPARE(channel.getId(), 1);
    QCOMPARE(channel.getName(), QString("新浪"));
    QCOMPARE(channel.getUrl(), QString("http://rss.sina.com.cn/news/marquee/ddt.xml"));

    channel = channels.at(1);
    QCOMPARE(channel.getId(), 2);
    QCOMPARE(channel.getName(), QString("网易"));
    QCOMPARE(channel.getUrl(), QString("http://news.163.com/special/00011K6L/rss_newstop.xml"));
}

void Test::getChannelByGroupId_test()
{
    QVector<Channel> channels = Channel::getChannelByGroupId(1);
    Channel channel = channels.at(0);
    QCOMPARE(channel.getId(), 3);
    QCOMPARE(channel.getName(), QString("QQ"));
    QCOMPARE(channel.getUrl(), QString("http://news.qq.com/newsgn/rss_newsgn.xml"));
}

void Test::getSystemRecommendChannels_test()
{
    Channel channel = Channel::getSystemRecommendChannels().at(0);
    QCOMPARE(channel.getName(), QString("网易"));
}

void Test::getUserRecommendChannels_test()
{
    Channel channel = Channel::getUserRecommendChannels().at(0);
    QCOMPARE(channel.getName(), QString("BBC"));
}

void Test::setRecommendChannels_test()
{
    //QVector<int> v;
    //v << 2;
    //Channel::setRecommendChannels(v);
}

void Test::addChannel_test()
{
    //QCOMPARE(Channel::addChannel(3, "aaa", "bbb"), 8);
}

void Test::removeChannel_test()
{
    //Channel::removeChannel(7);
}

void Test::setGroup_test()
{
    //Channel::setGroup(1, 10);
}

void Test::rename_test()
{
    //Channel::rename(2, "new name");
}

QTEST_MAIN(Test)
