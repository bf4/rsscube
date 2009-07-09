#include <QVector>
#include "test.h"
#include "../../RssCube/other/enums.h"
#include "../../RssCube/control/DatabaseController.h"

Test::Test()
{
    DatabaseController databaseController = DatabaseController::getInstance();
    databaseController.connect("../../RssCube/rss_cube.db");
}

void Test::localSearch_test()
{
    Article article = SearchController::getInstance().localSearch(MT_Fuzzy, RT_Unread, CT_Title, "sss").at(0);
    QCOMPARE(article.getId(), 1);

    article = SearchController::getInstance().localSearch(MT_Whole, RT_Read, CT_Summary, "ssssdddd").at(0);
    QCOMPARE(article.getId(), 2);
}

QTEST_MAIN(Test)
