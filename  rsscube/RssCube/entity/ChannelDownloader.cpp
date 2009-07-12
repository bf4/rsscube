// 2009-07-07 裴小星 创建框架
// 2009-07-08 裴小星 实现函数

#include <QString>
#include <QUrl>
#include <QIODevice>
#include <QTextStream>
#include "../other/macros.h"
#include "Article.h"
#include "ChannelDownloader.h"

ChannelDownloader::ChannelDownloader(bool writeDb) :
        QObject(NULL), mWriteDb(writeDb), mHttpAborted(false), mRssFormatError(false),
        mCurrentTag(""), mTitle(""), mPublishDate(""), mAuthor(""),
        mCategory(""), mDescription(""), mLink("")
{
    mHttp = new QHttp();
    mTimer = new QTimer();

    connect(mHttp, SIGNAL(done(bool)), this, SLOT(httpDownloaded(bool)));
    connect(mHttp, SIGNAL(readyRead(const QHttpResponseHeader &)),
             this, SLOT(parseRss(const QHttpResponseHeader &)));
    connect(mTimer, SIGNAL(timeout()), this, SLOT(httpTimeout()));
}

ChannelDownloader::~ChannelDownloader()
{
    DELETE(mHttp);
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
    mHttp->get(url.path());
    mHttp->close();

    mTimer->start(MAX_DOWNLOAD_TIME * 1000);    

    Article::logicRemove(mChannelId);
}

void ChannelDownloader::checkUrlAsync(const QString & urlString)
{
    mChannelId = 0;

    QUrl url(urlString);
    mHttp->setHost(url.host(), url.port(80));
    mHttp->get(url.path());
    mHttp->close();

    mTimer->start(MAX_DOWNLOAD_TIME * 1000);
}

void ChannelDownloader::parseRss(const QHttpResponseHeader &resp)
{
    xml.addData(mHttp->readAll());

    while (!xml.atEnd())
    {
        xml.readNext();

        if (xml.isStartElement())
        {
            mCurrentTag = xml.name().toString();
        }
        else if (xml.isEndElement())
        {            
            if (xml.name() == "item")
            {
                if (mWriteDb)
                {
                    Article::addArticle(mChannelId, mPublishDate, mCategory, mAuthor, mTitle, mDescription, mLink);
                }

                mCurrentTag = "";
                mTitle = "";
                mPublishDate = "";
                mAuthor = "";
                mCategory = "";
                mDescription = "";
                mLink = "";
            }
        }
        else if (xml.isCharacters() && !xml.isWhitespace())
        {
            if (mCurrentTag == "title") { mTitle += xml.text().toString();  }
            else if (mCurrentTag == "pubDate") { mPublishDate += xml.text().toString(); }
            else if (mCurrentTag == "author") { mAuthor += xml.text().toString(); }
            else if (mCurrentTag == "category") {  mCategory += xml.text().toString(); }
            else if (mCurrentTag == "description") { mDescription += xml.text().toString(); }
            else if (mCurrentTag == "link") { mLink += xml.text().toString(); }
        }
    }

    if (xml.error() && xml.error() != QXmlStreamReader::PrematureEndOfDocumentError)
    {
        mRssFormatError = true;
        mTimer->stop();
    }
}

void ChannelDownloader::httpDownloaded(bool error)
{
    mTimer->stop();

    if (mHttpAborted)  { return; }
    if (mRssFormatError)
    {
        if (mWriteDb) { Article::logicRecover(mChannelId); }
        mObserver->handleChannelDownloaded(mChannelId, DS_RssFormatError, this);
        return;
    }

    if(error)
    {
        if (mWriteDb) { Article::logicRecover(mChannelId); }
        mObserver->handleChannelDownloaded(mChannelId, DS_Timeout, this);
    }    
    else
    {
        Article::removeArticles(-mChannelId);
        mObserver->handleChannelDownloaded(mChannelId, DS_Success, this);
    }
}

void ChannelDownloader::httpTimeout()
{
    mHttpAborted = true;
    mHttp->abort();
    if (mWriteDb) { Article::logicRecover(mChannelId); }
    mObserver->handleChannelDownloaded(mChannelId, DS_Timeout, this);
}
