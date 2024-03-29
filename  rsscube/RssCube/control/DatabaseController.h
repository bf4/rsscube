// 2009-07-07 吴双 创建框架
// 2009-07-07 吴双 添加注释
// 2009-07-09 吴双 测试通过

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
    static DatabaseController & getInstance()
    {
        static DatabaseController instance;
        return instance;
    }

    /**
      Connect the database.
      @param databaseFilename
      The filename of the database file.
      */
    void connect(QString databaseFilename = "rss_cube.db");

    /**
      Close the database.
      */
    void close();

private:
    DatabaseController();

    /** The database */
    QSqlDatabase mDataBase;
};

#endif // DATABASECONTROLLER_H
