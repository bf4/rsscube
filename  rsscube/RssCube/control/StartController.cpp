// 2009-07-07 吴双 创建框架
// 2009-07-09 裴小星 实现函数

#include "StartController.h"
#include "DatabaseController.h"
#include "RefreshController.h"

StartController::StartController()
{
}

StartController::~StartController()
{
}

void StartController::initDatabase()
{    
    DatabaseController databaseController = DatabaseController::getInstance();
    databaseController.connect();    
}

void StartController::initRefresh()
{
    RefreshController::getInstance().init();
}
