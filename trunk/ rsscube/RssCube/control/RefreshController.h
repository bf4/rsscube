// 2009-07-07 裴小星 创建框架
// 2009-07-07 裴小星 添加注释

#ifndef REFRESHCONTROLLER_H
#define REFRESHCONTROLLER_H

#include <QObject>
#include <QVector>

#include "../other/enums.h"
#include "../other/interfaces.h"
#include "../entity/ChannelDownloader.h"

class RefreshController : public QObject, public IChannelDownloaderObserver
{
    Q_OBJECT

public:    
    ~RefreshController();

    /**
      Get the instance of the controller.
      @return
      The instance of the controller.
      */
    static const RefreshController & getInstance()
    {
        static RefreshController instance;
        return instance;
    }

    /**
      Init the controller. Start to refresh if sutoRefresh is set to true.
      */
    void init();

    /**
      Set the observer. When a channel is refreshed, the controller will notify the observer.
      @param observer
      The observer to notify.
      */
    void setObserver(IRefreshControllerObserver *observer);

    /**
      Update the refresh setting.
      */
    void updateRefreshSeting();

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
    RefreshController();

    /**
      excute the refresh operation.
      */
    void run();

    /** The timer to count when to start refresh after an interval. */
    QTimer* mTimer;

    /** The queue to save the downloader to start download. */
    QVector<ChannelDownloader*> mDownloadQueue;

    /** When a channel is downloaded, the observer will be notified. */
    IRefreshControllerObserver* mObserver;

    /** The number of channels refreshing. */
    int mRefreshCount;

    /** The max number the download threads at a same time. */
    enum { DOWNLOAD_LIMIT = 5 };

private slots:
    void handleTimeout();
};

#endif // REFRESHCONTROLLER_H
