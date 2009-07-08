// 2009-07-07 金欢 创建框架
// 2009-07-08 金欢 实现函数

#include <QSqlQuery>
#include <QVector>
#include <QVariant>
#include "Channel.h"

Channel::Channel()
{
}

Channel::~Channel()
{
}

int Channel::getId()
{
    return this->mId;
}

QString Channel::getName()
{
    return this->mName;
}

QString Channel::getUrl()
{
    return this->mUrl;
}

Channel Channel::getChannel(int channelId)
{
    Channel ret;

    QSqlQuery query;    
    query.prepare("SELECT id, name, url"
                  "FROM channels WHERE channel_id=:channel_id");
    query.bindValue(":channel_id", channelId);    
    query.exec();

    query.next();

    ret.mId=query.value(0).toInt();
    ret.mName=query.value(1).toString();
    ret.mUrl=query.value(2).toString();

    return ret;
}

QVector<Channel> Channel::getAllChannels()
{
    QVector<Channel> ret;
    QSqlQuery query;
    query.exec("SELECT id, name, url"
                  "FROM channels");

    while(query.next())
    {
        Channel channel;
        channel.mId=query.value(0).toInt();
        channel.mName=query.value(1).toString();
        channel.mUrl=query.value(2).toString();
        ret.push_back(channel);
    }

    return ret;
}

QVector<Channel> Channel::getChannelByGroupId(int groupId)
{
    QVector<Channel> ret;
    QSqlQuery query;
    query.prepare("SELECT id, name, url"
                  "FROM channels WHERE group_id=:groupId");

    query.bindValue(":groupId",groupId);
    query.exec();

    while(query.next())
    {
        Channel channel;
        channel.mId=query.value(0).toInt();
        channel.mName=query.value(1).toString();
        channel.mUrl=query.value(2).toString();
        ret.push_back(channel);
    }

    return ret;
}

QVector<Channel> Channel::getSystemRecommendChannels()
{
    QVector<Channel> ret;
    QSqlQuery query;
    query.prepare("SELECT id, name, url"
                  "FROM channel WHERE recommend=1");
    query.exec();

    while(query.next())
    {
        Channel channel;
        channel.mId=query.value(0).toInt();
        channel.mName=query.value(1).toString();
        channel.mUrl=query.value(2).toString();
        ret.push_back(channel);
    }
    return ret;
}

QVector<Channel> Channel::getUserRecommendChannels()
{
    QVector<Channel> ret;
    QSqlQuery query;
    query.prepare("SELECT id, name, url"
                  "FROM channel WHERE recommend=2");
    query.exec();

    while(query.next())
    {
        Channel channel;
        channel.mId=query.value(0).toInt();
        channel.mName=query.value(1).toString();
        channel.mUrl=query.value(2).toString();
        ret.push_back(channel);
    }
    return ret;

}

void Channel::setRecommendChannels(const QVector<int> &userSelectedChannels)
{
    QSqlQuery query;
    query.prepare("UPDATE channels"
                 "SET recommend=1"
                 "WHERE recommend=2");
    query.exec();

    for (int i =0; userSelectedChannels.size(); ++i)
    {
        //userSelectedChannels.at(i);
        query.prepare("UPDATE channels"
                    "SET recommend=2"
                    "WHERE id=userSelectedChannels.at(i)");
        query.exec();
    }
}

int Channel::addChannel(int groupId, const QString  name, const QString url)
{
    QSqlQuery query;
    query.prepare("INSERT INTO channels(group_id, name, url)"
                  "VALUES(:groupId, :name, :url)");
    query.bindValue(":groupId",groupId);
    query.bindValue(":name",name);
    query.bindValue(":url",url);

    query.exec();
    return query.lastInsertId().toInt();
}

void Channel::removeChannel(int id)
{
    QSqlQuery query;
    query.prepare("DELETE * FROM channels"
                  "WHERE id=:id");
    query.bindValue(":id",id);
    query.exec();
}

void Channel::setGroup(int id, int groupId)
{
    QSqlQuery query;
    query.prepare("UPDATE channels"
                  "SET group_id=:groupId"
                  "WHERE id=:id");
    query.bindValue(":groupId",groupId);
    query.bindValue(":id",id);
    query.exec();
}

void Channel::rename(int id, const QString &name)
{
    QSqlQuery query;
    query.prepare("UPDATE channels"
                  "SET name=:name"
                  "WHERE id=:id");
    query.bindValue(":name",name);
    query.bindValue(":id",id);
    query.exec();
}


