//2009-07-07 于宝 创建框架
//2009-07-07 于宝 添加注释
//2009-07-07 于宝 writeArticle()改为getArticleHtml()

#ifndef CHANNELCONTROLLER_H
#define CHANNELCONTROLLER_H

#include <QVector>
#include "../other/enums.h"
#include "../other/interfaces.h"
#include "../entity/Article.h"
#include "../entity/Channel.h"
#include "../entity/ChannelDownloader.h"

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
      set the observer when the url is checked
      @param observer
      the channel controller observer
      */
    void setObserver(IChannelControllerObserver *observer);

     /**
      get articles in the specific channel
      @param channelId
      a specific channel's id
      @return
      the articles in the specific
      */
    QVector<Article> getArticles(int channelId);

     /**
      add a new channel to a specific group
      @param groupId
      to specify the group to add the channel in
      @param name
      the new channel's name
      @param &url
      the channel's url
      @return
      the new channel's id
      */
    int addChannel(int groupId,const QString &name,const QString &url);

     /**
      to remove a channel
      @param channelId
      the id the channel to remove
      */
    void removeChannel(int channelId);

     /**
      to move a channel by dragging it onto a new group
      @param channelId
      the id of the channel to move
      @param newGroupId
      the id of the group which the channel is to move in
      */
    void dragChannel(int channelId,int newGroupId);

     /**
      to rename a channel
      @param channelId
      the id of the channel to rename
      @param newName
      the channel's newName
      */
    void renameChannel(int channelId,const QString &newName);

     /**
      to invoke the function writeHtml of the Aarticle class
      @param
      */
    QString getArticleHtml(int articleId);

     /**
       to check if a url is a valid url and if the source live up to the RSS standard
      */
    void checkUrl(const QString & url);

     /**
        to handle the channels that has been downloaded
      @param channelId
      the channels to handle
      @param downloaderToDelete
      a pointer pointing to a channelDownloader
      @param downloadState
      the download state
      */
    void handleChannelDownloaded(int channelId, DownloadState downloadState,
                                 ChannelDownloader* downloaderToDelete);

    /**
      When start to download the channel,
      the observer will be notified.
      @param channelId
      The id of the channel to download.
      */
    void handleStartDownload(int channelId);

private:
    ChannelController();

    /**  a pointer that observes action that checks the url*/
    IChannelControllerObserver *mObserver;
};

#endif // CHANNELCONTROLLER_H
