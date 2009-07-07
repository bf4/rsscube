//2009-07-07 吴双 创建框架

#ifndef STARTCONTROLLER_H
#define STARTCONTROLLER_H

class StartController
{
public:
    StartController();
    ~StartController();

    /**
      initialize this program, start refresh controller and open database
      */
    void init();
};

#endif // STARTCONTROLLER_H
