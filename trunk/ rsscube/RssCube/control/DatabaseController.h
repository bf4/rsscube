//2009-07-07 吴双 创建框架

#ifndef DATABASECONTROLLER_H
#define DATABASECONTROLLER_H

#include <QSqlDatabase>

class DatabaseController
{
public:
    DatabaseController();
    ~DatabaseController();

    /**
      connect the database
      */
    void connect();

    /**
      close the database
      */
    void close();

private:

    /** database */
    QSqlDatabase *mDataBase;
};

#endif // DATABASECONTROLLER_H
