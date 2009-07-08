// 2009-07-07 于宝 创建框架

#include "ChannelController.h"

ChannelController::ChannelController()
{
}

ChannelController::~ChannelController()
{
}

void ChannelController::setObserver(IChannelControllerObserver * observer)
{
}

QVector<Article> ChannelController::getArticles(int channelId)
{
}

int ChannelController::addChannel(int groupId,const QString &name,const QString &url)
{
}

void ChannelController::removeChannel(int channelId)
{
}

void ChannelController::dragChannel(int channelId,int newGroupId)
{
}

void ChannelController::renameChannel(int channelId,const QString &newName)
{
}

void ChannelController::refreshChannel(int channelId)
{
}

void ChannelController::refreshAllChannels()
{
}

void ChannelController::getArticleHtml(int articleId)
{
}

void ChannelController::checkUrl()
{
}

void ChannelController::handleChannelDownloaded(int channelId,ChannelDownloader* downloaderToDelete,
                                 DownloadState downloadState)
{
}
