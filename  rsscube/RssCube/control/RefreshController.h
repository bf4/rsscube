// 2009-07-07 裴小星 创建框架

#ifndef REFRESHCONTROLLER_H
#define REFRESHCONTROLLER_H

#include "../other/enums.h"
#include "../other/interfaces.h"
#include "../entity/ChannelDownloader.h"

#include <QVector>

class RefreshController : IChannelDownloaderObserver
{
public:
    RefreshController();
    ~RefreshController();

    /**
      Init the controller. Start to refresh if sutoRefresh is set to true.
      */
    void init();

    /**
      Set the oberver.When a channel is downloaded, the doloader will notify the observer.
      @param observer
      The observer to notify.
      */
    void setObserver(IRefreshControllerObserver *observer);

    /**
      Start to refresh all channels.
      */
    void refreshAll();

    /**
      Start to refresh a channel.
      @param channelId
      The id of the channel to refresh.
      */
    void refresh(int channelId);

    /**
      For the refresh controller will register as a observer of channel downloaders,
      when a channel downloader complete to refresh a channel, the controller will be notified.
      This function is used to handle this event.
      @param channelId
      The id of the channel downloaded.
      @param downloadState
      The download state (Success, Timeout, RssFormatError)
      @param downloaderToDelete
      The downloader to delete.
      */
    void handleChannelDownloaded(int channelId, DownloadState downloadState, ChannelDownloader *downloaderToDelete);

private:

    /**
      excute the refresh operation.
      */
    void run();

    /** The timer to count when to start refresh after an interval. */
    QTimer* mTimer;

    /** The queue to save the downloader to start download. */
    QVector<ChannelDownloader*> mDownloadQueue;

    /** The max number the download threads at a same time. */
    int mDownloadLimit;

    /** When a channel is downloaded, the observer will be notified. */
    IRefreshControllerObserver* mObserver;
};

#endif // REFRESHCONTROLLER_H
