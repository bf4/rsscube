// 2009-07-07 裴小星 创建框架

#ifndef REFRESHCONTROLLER_H
#define REFRESHCONTROLLER_H

#include "../other/enums.h"
#include "../other/interfaces.h"
#include "../entity/ChannelDownloader.h"

#include <QVector>

class RefreshController
{
public:
    RefreshController();
    ~RefreshController();
    void init();
    void setObserver(IRefreshControllerObserver *observer);
    void refreshAll();
    void refresh(int channelId);
    void handleChannelDownloaded(int channelId, DownloadState downloadState, ChannelDownloader *downloaderToDelete);

private:
    void run();

    QTimer* mTimer;
    QVector<ChannelDownloader*> mDownloadQueue;
    int mDownloadLimit;
    IRefreshControllerObserver* mObserver;
};

#endif // REFRESHCONTROLLER_H
