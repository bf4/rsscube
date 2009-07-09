// 2009-07-09 裴小星 编写测试

#include "test.h"
#include "../../RssCube/control/DatabaseController.h"

Test::Test()
{
    DatabaseController databaseController = DatabaseController::getInstance();
    databaseController.connect("../../RssCube/rss_cube.db");
}

void Test::getSubGroups_test()
{
    Group group = GroupController::getInstance().getSubGroups(0).at(0);
    QCOMPARE(group.getName(), QString("IT news"));

    group = GroupController::getInstance().getSubGroups(1).at(0);
    QCOMPARE(group.getId(), 5);
}

void Test::addGroup_test()
{
    //QCOMPARE(GroupController::getInstance().addGroup(10, "sdadadsa"), 12);
}

void Test::removeGroup_test()
{
    //GroupController::getInstance().removeGroup(12);
}

void Test::dragGroup_test()
{
    // GroupController::getInstance().dragGroup(11, 0);
}

void Test::renameGroup_test()
{
    //GroupController::getInstance().renameGroup(11, "xxxx");
}

QTEST_MAIN(Test)
