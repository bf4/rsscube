//2009-07-09 金欢 编写测试

#include <QString>
#include <QVector>
#include <QFile>
#include <iostream>
using namespace std;
#include "test.h"
#include "../../RssCube/control/DatabaseController.h"

Test::Test()
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));

    DatabaseController databaseController=DatabaseController::getInstance();
    databaseController.connect("../../RssCube/rss_cube.db");
}

void Test::getHtml_test()
{
    /*QString ret=Article::getHtml(1);
    QFile file("/home/yubao/out");
    if(file.open(QIODevice::WriteOnly))
    {
        QTextStream out(&file);
        out<<ret<<"\n";
    }*/
}

void Test::getArticlesByChannelId_test()
{/*
    QVector<Article> ret=Article::getArticlesByChannelId(1);    
    QCOMPARE(ret[0].getAuthor(), QString("Yule"));
    QCOMPARE(ret[1].getAuthor(), QString("Jane"));*/
}

void Test::getArticle_test()
{/*
    Article article=Article::getArticle(1);
    QCOMPARE(article.getAuthor(), QString("Yule"));
    QCOMPARE(article.getLink(), QString("http://www.google.com"));*/
}

void Test::localSearch_test()
{/*
    QVector<Article> ret=Article::localSearch(MT_Whole,RT_All,CT_Author,QString("XiaoXing"));
    QCOMPARE(ret[0].getCategory(),QString("IT news"));
    QCOMPARE(ret[2].getCategory(),QString("IT nine"));

    QVector<Article> ret1=Article::localSearch(MT_Fuzzy,RT_All,CT_Title,QString("ceo"));
    QCOMPARE(ret1[1].getAuthor(),QString("One"));
    QCOMPARE(ret1[2].getAuthor(),QString("Two"));

    QVector<Article> ret2=Article::localSearch(MT_Fuzzy,RT_Read,CT_Title,QString("ceo"));
    QCOMPARE(ret2[0].getAuthor(),QString("One"));*/
}

void Test::addArticle_test()
{
    Article::addArticle(1,QString("2009-07-09 20:29:21"),QString(""),QString(""),QString("中国国际消费电子博览会青岛开幕 带来数百亿订单  "),QString("新华网青岛７月９日电（记者李紫恒）主题为“全球共享中国机会”的“２００９中国国际消费电子博览会”，９日在青岛国际会展中心开幕。据介绍，全球３０多个国家和地区的７００多家采购商带来数百亿元的采购订单"),QString(" http://finance.people.com.cn/GB/9626633.html"));
    //QString title = item.firstChildElement("title").text();
    //QString publishDate = item.firstChildElement("pubDate").text();
    //QString author = item.firstChildElement("author").text();
    //QString category = item.firstChildElement("category").text();
    //QString description  = item.firstChildElement("description").text();
    //QString link = item.firstChildElement("link").text();



    Article::addArticle(mChannelId, publishDate, category, author, title, description, link);



  /*  int returnId=Article::addArticle(1,QString("2009-07-09 10:00:00"),QString("IT news"),QString("XiaoXing"),QString("The big 'NIU' in IT world!"),QString("XiaoXing is the big 'NIU' in IT world!"),QString("http://www.tudou.com"));
    Article article=Article::getArticle(returnId);
    QCOMPARE(article.getAuthor(), QString("XiaoXing"));*/
}

void Test::removeArticles_test()  //By observing the database,and it operates normally
{
    //int returnId=Article::addArticle(2,QString("2009-07-09 11:00:00"),QString("IT news"),QString("Kong"),QString("The big 'NIU' in IT world!"),QString("XiaoXing is the big 'NIU' in IT world!"),QString("http://www.tudou.com"));
    //Article article=Article::getArticle(returnId);
    //QCOMPARE(article.getAuthor(), QString("Kong"));

    //Article::removeArticles(2);
}

QTEST_MAIN(Test)
