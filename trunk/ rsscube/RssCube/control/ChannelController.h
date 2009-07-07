//2009-07-07 14：11于宝 创建ChannelController框架
#ifndef CHANNELCONTROLLER_H
#define CHANNELCONTROLLER_H
#include"../other/interfaces.h"
#include<QVector>
#include"../entity/Article.h"

class ChannelController
{
public:
    ChannelController();
    ~ChannelController();
    void setObserver(IChannelControllerObserver observer);
    QVector<Article> getArticles(int channelId);
    int addChannel(int groupId,const QString &name,const QString &url);
    void removeChannel(int channelId);
    void dragChannel(int channelId,int newGroupId);
    void renameChannel(int channelId,const QString &newName);
    void refreshChannel(int channelId);
    void refreshAllChannels();
    void writeArticle(int articleId);
    void checkUrl();
    void handleChannelDownloaded(int channelId,ChannelDownloader* downloaderToDelete,
                                 DownloadState downloadState);

private:
    IChannelControllerObserver *mObserver;
};

#endif // CHANNELCONTROLLER_H
