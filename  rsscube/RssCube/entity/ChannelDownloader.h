// 2009-07-07 裴小星 创建框架
// 2009-07-07 裴小星 添加注释

#ifndef CHANNELDOWNLOADER_H
#define CHANNELDOWNLOADER_H

#include <QObject>
#include <QHttp>
#include <QBuffer>
#include <QTimer>
#include <QDomDocument>
#include <QDomElement>
#include "../other/interfaces.h"
#include "../entity/Channel.h"

class ChannelDownloader : public QObject
{
    Q_OBJECT

public:

    /**
      Constructor
      @param writeDb
      If set to false, all downloaded articles will not be added to the database.
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
      Set the channel to dowmload.
      @param channelToDownload
      The channel to download
      */
    void setChannelToDownload(const Channel & channelToDownload);

    /**
      Start to download the channel.
      @param channelId
      The id of the channel to download.
      */
    void downloadChannelAsync();

private:

    /**
      Parse the RSS document.
      */
    void parseRss(const QString & rssXml);

    /**
      Parse the channel element of the RSS Document.
      @param channelElement
      The channel element of the RSS Document.
      */
    void parseChannelElement(const QDomElement & channelElement);

    /**
      Parse the child element of channel element.
      @param channelChildElement
      The child element of channel element.
      */
    void parseChannelChildElement(const QDomElement & channelChildElement);

    /** Use to download rss document by http. */
    QHttp* mHttp;

    /** Use to save the downloaded rss document. */
    QBuffer* mBuffer;

    /** The time to count when to shut down the http. */
    QTimer* mTimer;

    /** The channel to refresh. */
    Channel mChannel;

    /** If set to false, all downloaded articles will not be added to the database. */
    bool mWriteDb;

    /** When a channel is downloaded, the doloader will notify the observer. */
    IChannelDownloaderObserver* mObserver;

    /** Max time (seconds) to download the rss document. */
    enum { MAX_DOWNLOAD_TIME = 120 };

private slots:

    /**
      Receive the signal of QHttp instance when download completed.
      */
    void httpDownloaded(bool error);

    /**
      Receive the sinal of QTimer instance when download keep too long time.
      */
    void httpTimeout();
};

#endif // CHANNELDOWNLOADER_H
