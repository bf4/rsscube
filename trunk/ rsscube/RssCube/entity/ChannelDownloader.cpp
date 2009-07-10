// 2009-07-07 裴小星 创建框架
// 2009-07-08 裴小星 实现函数

#include <QString>
#include <QUrl>
#include <QIODevice>
#include <QTextStream>
#include "../other/macros.h"
#include "Article.h"
#include "ChannelDownloader.h"

ChannelDownloader::ChannelDownloader(bool writeDb) : QObject(NULL), mWriteDb(writeDb)
{
    mHttp = new QHttp();
    mBuffer = new QBuffer();
    mTimer = new QTimer();

    connect(mHttp, SIGNAL(done(bool)), this, SLOT(httpDownloaded(bool)));
    connect(mTimer, SIGNAL(timeout()), this, SLOT(httpTimeout()));    
}

ChannelDownloader::~ChannelDownloader()
{
    DELETE(mHttp);
    DELETE(mBuffer);
    DELETE(mTimer);
}

void ChannelDownloader::setObserver(IChannelDownloaderObserver *observer)
{
    mObserver = observer;
}

void ChannelDownloader::setChannelToDownload(const Channel & channelToDownload)
{
    mChannel = channelToDownload;
}

void ChannelDownloader::downloadChannelAsync()
{
    mChannelId = mChannel.getId();

    mObserver->handleStartDownload(mChannelId);

    QUrl url(mChannel.getUrl());
    mHttp->setHost(url.host(), url.port(80));

    mBuffer->open(QIODevice::WriteOnly);

    mHttp->get(url.path(), mBuffer);
    mHttp->close();

    mTimer->start(MAX_DOWNLOAD_TIME * 1000);
}

void ChannelDownloader::checkUrlAsync(const QString & urlString)
{
    mChannelId = 0;

    QUrl url(urlString);
    mHttp->setHost(url.host(), url.port(80));

    mBuffer->open(QIODevice::WriteOnly);

    mHttp->get(url.path(), mBuffer);
    mHttp->close();

    mTimer->start(MAX_DOWNLOAD_TIME * 1000);
}

void ChannelDownloader::parseRss(const QString & rssXml)
{
    QDomDocument rssDoc;
    rssDoc.setContent(rssXml);

    const QDomElement & channelElement = rssDoc.documentElement().firstChildElement("channel");
    if (channelElement.isNull())
    {
        mObserver->handleChannelDownloaded(mChannelId, DS_RssFormatError, this);
    }
    else
    {
        parseChannelElement(channelElement);
    }    
}

void ChannelDownloader::parseChannelElement(const QDomElement & channelElement)
{
    if (mWriteDb)
    {
        Article::removeArticles(mChannelId);

        QDomNode rssChannelChild = channelElement.firstChild();

        while (!rssChannelChild.isNull())
        {
            parseChannelChildElement(rssChannelChild.toElement());
            rssChannelChild = rssChannelChild.nextSibling();
        }
    }

    mObserver->handleChannelDownloaded(mChannelId, DS_Success, this);
}

void ChannelDownloader::parseChannelChildElement(const QDomElement & item)
{
    if (item.tagName() == "item")
    {
        QString title = item.firstChildElement("title").text();
        QString publishDate = item.firstChildElement("pubDate").text();
        QString author = item.firstChildElement("author").text();
        QString category = item.firstChildElement("category").text();
        QString description  = item.firstChildElement("description").text();
        QString link = item.firstChildElement("link").text();

        if (title.isNull()) { title = ""; }
        if (publishDate.isNull()) { publishDate = ""; }
        if (author.isNull()) { author = ""; }
        if (category.isNull()) { category = ""; }
        if (description.isNull()) { description = ""; }
        if (link.isNull()) { link = ""; }

        Article::addArticle(mChannelId, publishDate, category, author, title, description, link);
    }
}

void ChannelDownloader::httpDownloaded(bool error)
{
    mTimer->stop();

    if (error)
    {
        mObserver->handleChannelDownloaded(mChannelId, DS_Timeout, this);
    }
    else
    {
        mBuffer->close();

        mBuffer->open(QIODevice::ReadOnly);
        QTextStream stream(mBuffer);
        QString rssXml = stream.readAll();
        mBuffer->close();

        parseRss(rssXml);        
    }
}

void ChannelDownloader::httpTimeout()
{
    mTimer->stop();
    mHttp->abort();
}
