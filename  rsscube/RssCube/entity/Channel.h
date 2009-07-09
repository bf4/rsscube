// 2009-07-07 金欢 创建框架
// 2009-07-07 金欢 添加注释
// 2009-07-09 裴小星 测试通过

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
      get the channel by id
      @param channelId
      the id of the channel
      @return
      the channel
      */
    static Channel getChannel(int channelId);

    /**
      when fresh, freshing all the Channels
      @return
      return all the newest Channels
      */
    static QVector<Channel> getAllChannels();

    /**
      get all the channels of a specific group by the groupId
      @param groupId
      the chosen group's id
      @return
      return the channels of the group
      */
    static QVector<Channel> getChannelByGroupId(int groupId);

    /**
      get the system's recommend channels
      @return
      return the system's recommend channels
      */
    static QVector<Channel> getSystemRecommendChannels();

    /**
      get the user's recommend channels
      @return
      return the user's recommend channels
      */
    static QVector<Channel> getUserRecommendChannels();

    /**
      set the channels' recommend(SystemRecommend or UserRecommend)
      @param userSelectedChannels
      the new recommend of channel
      */
    static void setRecommendChannels(const QVector<int> &userSelectedChannels);

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
    static int addChannel(int groupId, const QString name, const QString url);

    /**
      remove the channel by id
      @param id
      the id of the channel which is going to be deleted
      */
    static void removeChannel(int id);

    /**
      set the channel's new parent group
      @param id
      the id of the chosen channel
      @param groupId
      the new group's id
      */
    static void setGroup(int id, int groupId);

    /**
      set the channel's new name
      @param id
      the id of the chosen channel
      @param name
      the new name of the chosen id
      */
    static void rename(int id, const QString &name);

private:
    int mId;              /** the id of the Channels */
    QString mName;      /** the name of the Channels */
    QString mUrl;         /** the url of the Channels */

};

#endif // CHANNEL_H
