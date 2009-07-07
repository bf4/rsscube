//2009-07-07 14:20 于宝创建Recommend框架


#ifndef RECOMMENDCONTROLLER_H
#define RECOMMENDCONTROLLER_H
#include<QVector>
#include"../entity/Channel.h"

class RecommendController
{
public:
    RecommendController();
    ~RecommendController();
    QVector<Channel> getSystemRecommendChannels();
    QVector<Channel> getUserRecommendChannels();
    void setRecommendChannels(const QVector<int> &systemChannels,
                              const QVector<int> &userChannels);
};

#endif // RECOMMENDCONTROLLER_H
