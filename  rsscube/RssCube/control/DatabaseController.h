//2009-07-07 吴双构建控制类DatabaseController

#ifndef DATABASECONTROLLER_H
#define DATABASECONTROLLER_H

#include <QSqlDatabase>

class DatabaseController
{
public:
    DatabaseController();
    ~DatabaseController();

    void connect();
    void close();

private:
    QSqlDatabase *mDataBase;
};

#endif // DATABASECONTROLLER_H
