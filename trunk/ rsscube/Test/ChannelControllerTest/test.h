#ifndef TEST_H
#define TEST_H

#include <QtTest/QtTest>

#include "../../RssCube/control/ChannelController.h"

class Test : public QObject
{
    Q_OBJECT

public:
    Test();

private slots:
    void getArticles_test();
    void addChannel_test();
    void removeChannel_test();
    void dragChannel_test();
    void renameChannel_test();
    void getArticleHtml_test();
    void checkUrl_test();
};

#endif // TEST_H
