// 2009-07-07 吴双 创建框架
// 2009-07-09 裴小星 实现函数

#include "../entity/Article.h"
#include "ExitController.h"
#include "DatabaseController.h"

ExitController::ExitController()
{
}

ExitController::~ExitController()
{
}

void ExitController::exit()
{
    Article::clearArticles();
    DatabaseController databseController = DatabaseController::getInstance();
    databseController.close();    
}

