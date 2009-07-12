// 2009-07-07 裴小星 创建框架
// 2009-07-07 裴小星 添加注释
// 2009-07-09 于宝 测试通过

#ifndef CHANNELDOWNLOADER_H
#define CHANNELDOWNLOADER_H

#include <QObject>
#include <QString>
#include <QHttp>
#include <QBuffer>
#include <QTimer>
#include <QXmlStreamReader>
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
      Set the oberver. When a channel is downloaded, the doloader will notify the observer.
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

    /**
      Start to check the url.
      @param url
      The url to check.
      */
    void checkUrlAsync(const QString & urlString);

private:
    /** Use to download rss document by http. */
    QHttp* mHttp;

    /** The time to count when to shut down the http. */
    QTimer* mTimer;

    /** The channel to refresh. */
    Channel mChannel;

    /** The id of the channel */
    int mChannelId;

    /** If set to false, all downloaded articles will not be added to the database. */
    bool mWriteDb;

    /** Whether http connection is aborted.  */
    bool mHttpAborted;

    /** Whether the rss format has error. */
    bool mRssFormatError;

    /** When a channel is downloaded, the doloader will notify the observer. */
    IChannelDownloaderObserver* mObserver;

    /** THe tag and the attributes of articles. */
    QXmlStreamReader xml;
    QString mCurrentTag;
    QString mTitle;
    QString mPublishDate;
    QString mAuthor;
    QString mCategory;
    QString mDescription;
    QString mLink;

    /** Max time (seconds) to download the rss document. */
    enum { MAX_DOWNLOAD_TIME = 30 };

private slots:

    /**
      Parse the RSS document.
      */
    void parseRss(const QHttpResponseHeader &resp);

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
