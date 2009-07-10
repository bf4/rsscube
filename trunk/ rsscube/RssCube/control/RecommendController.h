// 2009-07-07 于宝 创建框架
// 2009-07-07 于宝 添加注释
// 2009-07-09 裴小星 测试通过

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
      Get the channels that are recommended by the system
      @return
      The channels that are recommended by the system
      */
    QVector<Channel> getSystemRecommendChannels();

    /**
      Get the channels that are recommended by the user
      @return
      The channels that are recommended by the user
      */
    QVector<Channel> getUserRecommendChannels();

    /**
      Set the new recommend channels.
      @param &userSelectedChannels
      The recommend channels that selected by user.
      */
    void setRecommendChannels(const QVector<int> &userSelectedChannels);

private:
    RecommendController();
};

#endif // RECOMMENDCONTROLLER_H
