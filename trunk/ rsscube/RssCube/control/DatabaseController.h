// 2009-07-07 吴双 创建框架
// 2009-07-07 吴双 添加注释

#ifndef DATABASECONTROLLER_H
#define DATABASECONTROLLER_H

#include <QSqlDatabase>

class DatabaseController
{
public:
    ~DatabaseController();

    /**
      Get the instance of the controller.
      @return
      The instance of the controller.
      */
    static const DatabaseController & getInstance()
    {
        static DatabaseController instance;
        return instance;
    }

    /**
      connect the database
      */
    void connect();

    /**
      close the database
      */
    void close();

private:
    DatabaseController();

    /** database */
    QSqlDatabase *mDataBase;
};

#endif // DATABASECONTROLLER_H
