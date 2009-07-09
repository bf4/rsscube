// 2009-07-09 孔乂宇 编写测试

#include "test.h"
#include "../../RssCube/control/DatabaseController.h"

Test::Test()
{
    DatabaseController databaseController = DatabaseController::getInstance();
    databaseController.connect("../../RssCube/rss_cube.db");
}

void Test::getSubGroups_test()
{
    Group group = Group::getSubGroups(2).at(0);
    QCOMPARE(group.getId(),10);
    QCOMPARE(group.getName(),QString("news"));
}

void Test::addGroup_test()
{
    //int id =Group::addGroup(3, "blog");
    //QCOMPARE(id, 11);
}

void Test::removeGroup_test()
{
    //Group::removeGroup(11);
}

void Test::renameGroup_test()
{
    //Group::renameGroup(11,"blogssss");
}

void Test::setParent_test()
{
    //Group::setParent(11,4);
}

QTEST_MAIN(Test)
