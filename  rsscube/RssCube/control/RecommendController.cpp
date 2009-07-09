// 2009-07-07 于宝 创建框架
// 2009-07-09 于宝 实现函数

#include "RecommendController.h"
#include "../entity/Channel.h"

RecommendController::RecommendController()
{
}

RecommendController::~RecommendController()
{
}

QVector<Channel> RecommendController::getSystemRecommendChannels()
{
    return Channel::getSystemRecommendChannels();
}

QVector<Channel> RecommendController::getUserRecommendChannels()
{
    return Channel::getUserRecommendChannels();
}

void RecommendController::setRecommendChannels(const QVector<int> &userSelectedChannels)
{
    Channel::setRecommendChannels(userSelectedChannels);
}
