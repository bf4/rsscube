//2009-07-07 金欢 创建Channel框架

#ifndef CHANNEL_H
#define CHANNEL_H

#include <QString>

class Channel
{
public:
    Channel();
    ~Channel();

    /**
      get the Channel's id
      @return
      return the Channel's id
      */
    int getId();

    /**
      get the Channel's name
      @return
      return the Channel's name
      */
    QString getName();

    /**
      get the Channel's url
      @return
      return the Channel's url
      */
    QString getUrl();

    /**
      when fresh, freshing all the Channels
      @return
      return all the newest Channels
      */
    QVector<Channel> getAllChannel();

    /**
      get all the channels of a specific group by the groupId
      @param groupId
      the chosen group's id
      @return
      return the channels of the group
      */
    QVector<Channel> getChannelByGroupId(int groupId);

    /**
      get the system's recommend channels
      @return
      return the system's recommend channels
      */
    QVector<Channel> getSystemRecommendChannels();

    /**
      get the user's recommend channels
      @return
      return the user's recommend channels
      */
    QVector<Channel> getUserRecommendChannels();

    /**
      add new channel
      @param groupId
      get the id of the group which the new channel is going to add
      @param name
      input the new channel's name
      @param url
      input the new channel's url
      @return
      return the new channel's id
      */
    int addChannel(int groupId, const QString name, const QString url);

    /**
      remove the channel by id
      @param id
      the id of the channel which is going to be deleted
      */
    void removeChannel(int id);

    /**
      set the channel's new parent group
      @param id
      the id of the chosen channel
      @param groupId
      the new group's id
      */
    void setGroup(int id, int groupId);

    /**
      set the channel's new name
      @param id
      the id of the chosen channel
      @param name
      the new name of the chosen id
      */
    void rename(int id, const QString &name);

    /**
      set the recommend channels
      @param systemChannels
      the id of the systemChannels
      @param userChannels
      the id of the userChannels
      */
    void setRecommendChannels(const QVector<int> &systemChannels, const QVector<int> &userChannels);

private:
    int mId;              /** the id of the Channels */
    QString mName;      /** the name of the Channels */
    QString mUrl;         /** the url of the Channels */


};

#endif // CHANNEL_H
