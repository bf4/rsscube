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

QTEST_MAIN(Test)
