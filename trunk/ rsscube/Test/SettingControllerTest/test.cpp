#include "test.h"
#include "../../RssCube/control/DatabaseController.h"

#include <iostream>

using namespace std;

Test::Test()
{
    DatabaseController controller =  DatabaseController::getInstance();
    controller.connect("../../RssCube/rss_cube.db");
    SettingController::getInstance().setObserver(this);
}

void Test::handleDisplaySettingChanged(ReadType readType)
{
    cout << "handleDisplaySettingChanged:" << endl;

    switch(readType)
    {
        case RT_All:
            cout << "All" << endl;;
            break;
        case RT_Read:
            cout << "Read" << endl;;
            break;
        case RT_Unread:
            cout << "Unread" << endl;;
            break;
    }

    cout << endl;
}

void Test::changeRreshSetting_test()
{
    SettingController::getInstance().changeRreshSetting(true, 100.0f);
    QCOMPARE(SettingController::getInstance().getSetting().getAutoRefresh(), true);
    QCOMPARE(SettingController::getInstance().getSetting().getRefreshInterval(), 100.0f);

    SettingController::getInstance().changeRreshSetting(false, 10.0f);
    QCOMPARE(SettingController::getInstance().getSetting().getAutoRefresh(), false);
    QCOMPARE(SettingController::getInstance().getSetting().getRefreshInterval(), 10.0f);
}

void Test::changeDisplaySetting_test()
{
    SettingController::getInstance().changeDisplaySetting(RT_Unread);
    QCOMPARE(SettingController::getInstance().getSetting().getDisplayType(), RT_Unread);

    SettingController::getInstance().changeDisplaySetting(RT_Read);
    QCOMPARE(SettingController::getInstance().getSetting().getDisplayType(), RT_Read);

    SettingController::getInstance().changeDisplaySetting(RT_All);
    QCOMPARE(SettingController::getInstance().getSetting().getDisplayType(), RT_All);
}

QTEST_MAIN(Test)
