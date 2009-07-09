//2009-07-09 金欢 编写测试

#ifndef TEST_H
#define TEST_H

#include <QtTest/QtTest>
#include "../../RssCube/entity/Article.h"

class Test : public QObject
{
    Q_OBJECT
public:
    Test();

private slots:
    //void test();
    void getHtml_test();
    void getArticlesByChannelId_test();
    void getArticle_test();
    void localSearch_test();
    void addArticle_test();
    void removeArticles_test();
};

#endif // TEST_H
