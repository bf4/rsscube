//2009-07-07 于宝创建框架
//2009-07-07 于宝添加注释

#ifndef RECOMMENDCONTROLLER_H
#define RECOMMENDCONTROLLER_H
#include<QVector>
#include"../entity/Channel.h"

class RecommendController
{
public:    
    ~RecommendController();

    /**
      Get the instance of the controller.
      @return
      The instance of the controller.
      */
    static RecommendController & getInstance()
    {
        static RecommendController instance;
        return instance;
    }

    /**
      get the channels that are recommended by the system
      @return
      tthe channels that are recommended by the system
      */
    QVector<Channel> getSystemRecommendChannels();

    /**
      get the channels that are recommended by the user
      @return
      the channels that are recommended by the user
      */
    QVector<Channel> getUserRecommendChannels();

    /**
      to set a general channel a user recommend channel or a system recommend channel
      @param &systemChannel
      system recommend channel
      @param &userChannel
      user recommend channels
      */
    void setRecommendChannels(const QVector<int> &userSelectedChannels);

private:
    RecommendController();
};

#endif // RECOMMENDCONTROLLER_H
