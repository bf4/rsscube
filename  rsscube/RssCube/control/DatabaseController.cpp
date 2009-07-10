// 2009-07-07 吴双 创建框架
// 2009-07-08 裴小星 实现函数

#include <QSqlDatabase>
#include "DatabaseController.h"

DatabaseController::DatabaseController()
{
}

DatabaseController::~DatabaseController()
{
}

void DatabaseController::connect(QString databaseFilename)
{
    mDataBase = QSqlDatabase::addDatabase("QSQLITE");
    mDataBase.setDatabaseName(databaseFilename);
    mDataBase.open();
}

void DatabaseController::close()
{
    mDataBase.close();
}
