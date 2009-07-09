#include "test.h"

Test::Test()
{

}

void Test::changeRefreshSettingBeforeStart_test()
{
    Setting::changeRefreshSetting(true, 100.f);
}

void Test::changeRefreshSettingAfterStart_test()
{
    StartController::getInstance().init();
    Setting::changeRefreshSetting(true, 100.f);
}



QTEST_MAIN(Test)
