// 2009-07-07 裴小星 创建框架
// 2009-07-07 裴小星 添加注释

#ifndef CHANNELDOWNLOADER_H
#define CHANNELDOWNLOADER_H

#include <QHttp>
#include <QBuffer>
#include <QTimer>
#include "../other/interfaces.h"
#include "../entity/Channel.h"

class ChannelDownloader
{

public:

    /**
      @param writeDb
      If set to false, all downloaded articles will not add to the database.
      */
    ChannelDownloader(bool writeDb = true);

    ~ChannelDownloader();

    /**
      Set the oberver.When a channel is downloaded, the doloader will notify the observer.
      @param observer
      The observer to notify.
      */
    void setObserver(IChannelDownloaderObserver *observer);

    /**
      Start to download the channel.
      @param channelId
      The id of the channel to download.
      */
    void downloadChannelAsync(int channelId);

    /**
      Receive the signal of QHttp instance when download completed.
      */
    void httpDownloaded();

    /**
      Receive the sinal of QTimer instance when download keep too long time.
      */
    void httpTimeout();

private:

    /** Use to download rss document by http. */
    QHttp* mHttp;

    /** Use to save the downloaded rss document. */
    QBuffer* mBuffer;

    /** The channel to refresh. */
    Channel* mChannel;

    /** The time to count when to shut down the http. */
    QTimer mTimer;

    /** If set to false, all downloaded articles will not be added to the database. */
    bool mWriteDb;

    /** When a channel is downloaded, the doloader will notify the observer. */
    IChannelDownloaderObserver* mObserver;
};

#endif // CHANNELDOWNLOADER_H
