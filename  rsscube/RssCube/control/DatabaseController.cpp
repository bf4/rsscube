// 2009-07-07 吴双 创建框架
// 2009-07-07 于宝 实现函数

#include "DatabaseController.h"
#include <QSqlDatabase>

DatabaseController::DatabaseController()
{
}

DatabaseController::~DatabaseController()
{
}

void DatabaseController::connect()
{
    mDataBase = &QSqlDatabase::addDatabase("QSQLITE");
    mDataBase->setDatabaseName("rss_cube.db");
    mDataBase->open();
}

void DatabaseController::close()
{
    mDataBase->close();
}
