// 2009-07-07 于宝 创建框架

#include <QSqlQuery>
#include <QVariant>
#include "ChannelController.h"
#include "../other/macros.h"

ChannelController::ChannelController()
{
}

ChannelController::~ChannelController()
{
}

void ChannelController::setObserver(IChannelControllerObserver * observer)
{
    mObserver=observer;
}

QVector<Article> ChannelController::getArticles(int channelId)
{
    return Article::getArticlesByChannelId(channelId);
}

int ChannelController::addChannel(int groupId,const QString &name,const QString &url)
{
    return Channel::addChannel(groupId,name,url);
}

void ChannelController::removeChannel(int channelId)
{
    Channel::removeChannel(channelId);
}

void ChannelController::dragChannel(int channelId,int newGroupId)
{
    QSqlQuery query;
    query.prepare("update channels set group_id=:groupId where channel_id=:channelId");
    query.bindValue(":groupId",newGroupId);
    query.bindValue(":channelId",channelId);
    query.exec();
}

void ChannelController::renameChannel(int channelId,const QString &newName)
{
    Channel::rename(channelId,newName);
}


QString ChannelController::getArticleHtml(int articleId)
{
    return Article::getHtml(articleId);
}

void ChannelController::checkUrl(const QString & url)
{
    ChannelDownloader *loader=new ChannelDownloader(false);
    loader->setObserver(this);
    loader->checkUrlAsync(url);
}

void ChannelController::handleChannelDownloaded(int channelId, DownloadState downloadState,
                                                ChannelDownloader* downloaderToDelete)
{
    DELETE(downloaderToDelete);
    mObserver->handleUrlChecked(downloadState);
}

void ChannelController::handleStartDownload(int channelId)
{
}
