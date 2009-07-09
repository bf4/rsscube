#include "test.h"

void Test::exitBeforeStart_test()
{
    ExitController::getInstance().exit();
}

void Test::exitAfterStart_test()
{
    StartController::getInstance().init();
    ExitController::getInstance().exit();
}

QTEST_MAIN(Test)
