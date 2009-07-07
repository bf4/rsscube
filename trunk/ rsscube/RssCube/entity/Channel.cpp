//2009-07-07 金欢 创建Channel框架

#include "Channel.h"
#include <QVector>

Channel::Channel()
{
}

Channel::~Channel()
{
}

int Channel::getId()
{
}

QString Channel::getName()
{
}

QString Channel::getUrl()
{
}

QVector<Channel> Channel::getAllChannel()
{
}

QVector<Channel> Channel::getChannelByGroupId(int groupId)
{
}

QVector<Channel> Channel::getSystemRecommendChannels()
{
}

QVector<Channel> Channel::getUserRecommendChannels()
{
}

int Channel::addChannel(int groupId, const QString  name, const QString url)
{
}

void Channel::removeChannel(int id)
{
}

void Channel::setGroup(int id, int groupId)
{
}

void Channel::rename(int id, const QString &name)
{
}

void Channel::setRecommendChannels(const QVector<int> &systemChannels, const QVector<int> &userChannels)
{
}
