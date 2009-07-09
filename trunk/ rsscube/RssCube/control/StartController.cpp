// 2009-07-07 吴双 创建框架
// 2009-07-09 裴小星 测试通过

#include "StartController.h"
#include "DatabaseController.h"
#include "RefreshController.h"

StartController::StartController()
{
}

StartController::~StartController()
{
}

void StartController::init()
{    
    DatabaseController databaseController = DatabaseController::getInstance();
    databaseController.connect();
    RefreshController::getInstance().init();
}
