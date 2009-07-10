// 2009-07-10 裴小星 编写测试

#include "test.h"
#include "../../RssCube/control/DatabaseController.h"

Test::Test()
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));

    DatabaseController databaseController = DatabaseController::getInstance();
    databaseController.connect("../../RssCube/rss_cube.db");
}

void Test::getArticles_test()
{
    Article article = ChannelController::getInstance().getArticles(1).at(0);
    QCOMPARE(article.getId(), 1);
    article = ChannelController::getInstance().getArticles(1).at(1);
    QCOMPARE(article.getId(), 2);
}

void Test::addChannel_test()
{
    //QCOMPARE(ChannelController::getInstance().addChannel(0,"aaa", "xxxx"), 3);
}

void Test::removeChannel_test()
{
    //ChannelController::getInstance().removeChannel(3);
}

void Test::dragChannel_test()
{
    //ChannelController::getInstance().dragChannel(2, 100);
}

void Test::renameChannel_test()
{
    //ChannelController::getInstance().renameChannel(2, "zzz");
}

void Test::getArticleHtml_test()
{
    QString ret = ChannelController::getInstance().getArticleHtml(1);
    QFile file("out");
    if(file.open(QIODevice::WriteOnly))
    {
        QTextStream out(&file);
        out<<ret<<"\n";
    }
}

void Test::checkUrl_test()
{
}

QTEST_MAIN(Test)
