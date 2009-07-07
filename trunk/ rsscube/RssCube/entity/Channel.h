//2009-07-07 金欢 创建Channel框架

#ifndef CHANNEL_H
#define CHANNEL_H

#include <QString>

class Channel
{
public:
    Channel();
    ~Channel();
    int getId();
    QString getName();
    QString getUrl();

    QVector<Channel> getAllChannel();
    Channel getChannel(int id);
    QVector<Channel> getChannelByGroupId(int groupId);
    QVector<Channel> getSystemRecommendChannels();
    QVector<Channel> getUserRecommendChannels();

    int addChannel(const QString name, const QString url);
    void removeChannel(int id);
    void setGroup(int id, int groupId);
    void rename(int id, const QString &name);
    void setRecommendChannels(const QVector<int> &systemChannels, const QVector<int> &userChannels);

private:
    int mId;
    QString mName;
    QString mUrl;


};

#endif // CHANNEL_H
