// 2009-07-07 于宝 创建框架
// 2009-07-07 于宝 添加注释
// 2009-07-07 于宝 writeArticle()改为getArticleHtml()
// 2009-07-10 裴小星 测试通过

#ifndef CHANNELCONTROLLER_H
#define CHANNELCONTROLLER_H

#include <QVector>
#include "../other/enums.h"
#include "../other/interfaces.h"
#include "../entity/Article.h"
#include "../entity/Channel.h"
#include "../entity/ChannelDownloader.h"

/**
  A channel downloader is used to download a channel.
  When download completed, the downloader should be destroyed.
  */
class ChannelController: IChannelDownloaderObserver
{
public:    
    ~ChannelController();

    /**
      Get the instance of the controller.
      @return
      The instance of the controller.
      */
    static ChannelController & getInstance()
    {
        static ChannelController instance;
        return instance;
    }

     /**
      Set the observer. When the url is checked, the observer will be notified.
      @param observer
      The observer to notify.
      */
    void setObserver(IChannelControllerObserver *observer);

     /**
      Get articles in the specific channel.
      @param channelId
      The id of the specific channel.
      @return
      The articles in the specific channel.
      */
    QVector<Article> getArticles(int channelId);

     /**
      Add a new channel to a specific group
      @param groupId
      The id of the specific group.
      @param name
      The name of the added channel.
      @param &url
      The url of the added channel.
      @return
      The id of the added channel.
      */
    int addChannel(int groupId,const QString &name,const QString &url);

     /**
      Remove a channel with the specific id.
      @param channelId
      The id of the channel to remove.
      */
    void removeChannel(int channelId);

     /**
      Move a channel by dragging it onto a new group.
      @param channelId
      The id of the channel to move.
      @param newGroupId
      The id of the group which the channel is to move in.
      */
    void dragChannel(int channelId,int newGroupId);

     /**
      Rename a channel.
      @param channelId
      The id of the channel to rename.
      @param newName
      The new name of the channel.
      */
    void renameChannel(int channelId,const QString &newName);

     /**
      Get the html format descrtition of the article with the specific id.
      @param articleId
      The id of the article.
      */
    QString getArticleHtml(int articleId);

     /**
       Check whether the specific url is a valid url and whether the source live up to the RSS standard.
       @param url
       The url to check.
      */
    void checkUrl(const QString & url);

    /**
      When start to download the channel,
      the observer will be notified.
      @param channelId
      The id of the channel to download.
      */
    void handleStartDownload(int channelId);

    /**
      When the downloader compelete to download a channel,
      the observer will be notified.
      This function is used to handle this event.
      @param channelId
      The id of the channel to download.
      @param downloadState
      The downloadState (Success, Timeout, RssFomatError).
      @param downloaderToDelete
      The downloader to delete
      */
    void handleChannelDownloaded(int channelId, DownloadState downloadState,
                                 ChannelDownloader* downloaderToDelete);

private:
    ChannelController();

    /**  The observer to notify when the url is checked. */
    IChannelControllerObserver *mObserver;
};

#endif // CHANNELCONTROLLER_H
