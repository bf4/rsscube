// 2009-07-08 裴小星 编写测试

#include "test.h"
#include "../../RssCube/control/DatabaseController.h"

Test::Test()
{
    DatabaseController databaseController = DatabaseController::getInstance();
    databaseController.connect("../../RssCube/rss_cube.db");
}

void Test::getSettingInfo_test()
{
    Setting setting = Setting::getSettingInfo();
    QCOMPARE(setting.getAutoRefresh(), false);
    QCOMPARE(setting.getRefreshInterval(), 10.f);
    QCOMPARE(setting.getDisplayType(), RT_All);
}

void Test::changeRefreshSetting_test()
{
    Setting::changeRefreshSetting(true, 100.f);
    Setting setting = Setting::getSettingInfo();
    QCOMPARE(setting.getAutoRefresh(), true);
    QCOMPARE(setting.getRefreshInterval(), 100.f);

    Setting::changeRefreshSetting(false, 10.f);
    setting = Setting::getSettingInfo();
    QCOMPARE(setting.getAutoRefresh(), false);
    QCOMPARE(setting.getRefreshInterval(), 10.f);
}

void Test::changeDisplaySetting_test()
{
    Setting::changeDisplaySetting(RT_Unread);
    Setting setting = Setting::getSettingInfo();
    QCOMPARE(setting.getDisplayType(), RT_Unread);

    Setting::changeDisplaySetting(RT_All);
    setting = Setting::getSettingInfo();
    QCOMPARE(setting.getDisplayType(), RT_All);
}

QTEST_MAIN(Test)
