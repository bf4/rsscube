//2009-07-07 14:20 于宝创建Recommend框架
//2009-07-07 16:40 于宝添加注释

#ifndef RECOMMENDCONTROLLER_H
#define RECOMMENDCONTROLLER_H
#include<QVector>
#include"../entity/Channel.h"

class RecommendController
{
public:
    RecommendController();
    ~RecommendController();
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
    void setRecommendChannels(const QVector<int> &systemChannels,
                              const QVector<int> &userChannels);
};

#endif // RECOMMENDCONTROLLER_H
