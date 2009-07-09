// 2009-07-07 吴双 创建框架
// 2009-07-07 吴双 添加注释
// 2009-07-09 吴双 测试通过

#ifndef STARTCONTROLLER_H
#define STARTCONTROLLER_H

class StartController
{
public:
    ~StartController();

    /**
      Get the instance of the controller.
      @return
      The instance of the controller.
      */
    static StartController & getInstance()
    {
        static StartController instance;
        return instance;
    }

    /**
      initialize this program, start refresh controller and open database
      */
    void init();

private:
    StartController();
};

#endif // STARTCONTROLLER_H
