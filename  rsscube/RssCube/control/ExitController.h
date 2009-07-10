// 2009-07-07 吴双 创建框架
// 2009-07-07 吴双 添加注释
// 2009-07-09 吴双 测试通过

#ifndef EXITCONTROLLER_H
#define EXITCONTROLLER_H

class ExitController
{
public:
    ~ExitController();

    /**
      Get the instance of the controller.
      @return
      The instance of the controller.
      */
    static ExitController & getInstance()
    {
        static ExitController instance;
        return instance;
    }

    /**
      End the program. Also close the database.
      */
    void exit();

private:
    ExitController();
};

#endif // EXITCONTROLLER_H
