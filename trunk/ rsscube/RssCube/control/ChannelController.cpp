// 2009-07-07 于宝 创建框架
// 2009-07-08 于宝 实现函数

#include <QSqlQuery>
#include <QVariant>
#include "../other/macros.h"
#include "RefreshController.h"
#include "ChannelController.h"

ChannelController::ChannelController()
{
}

ChannelController::~ChannelController()
{
}

void ChannelController::setObserver(IChannelControllerObserver *observer)
{
    mObserver = observer;
}

QVector<Article> ChannelController::getArticles(int channelId)
{
    return Article::getArticlesByChannelId(channelId);
}

int ChannelController::addChannel(int groupId, const QString &name, const QString &url)
{
    int id = Channel::addChannel(groupId, name, url);
    RefreshController::getInstance().refresh(id);
    return id;
}

void ChannelController::removeChannel(int channelId)
{
    Channel::removeChannel(channelId);
}

void ChannelController::dragChannel(int channelId, int newGroupId)
{
    Channel::setGroup(channelId, newGroupId);
}

void ChannelController::renameChannel(int channelId, const QString &newName)
{
    Channel::rename(channelId,newName);
}

QString ChannelController::getArticleHtml(int articleId)
{
    return Article::getHtml(articleId);
}

bool ChannelController::getArticleIsRead(int articleId)
{
    return Article::getArticle(articleId).getIsRead();
}

void ChannelController::setArticleIsRead(int articleIid)
{
    Article::setRead(articleIid);
}

void ChannelController::checkUrl(const QString & url)
{
    ChannelDownloader *loader = new ChannelDownloader(false);
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
