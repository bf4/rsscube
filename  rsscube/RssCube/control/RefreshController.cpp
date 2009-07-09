// 2009-07-07 裴小星 创建框架
// 2009-07-08 裴小星 实现函数

#include "../other/macros.h"
#include "../entity/Setting.h"
#include "../entity/Channel.h"
#include "RefreshController.h"

RefreshController::RefreshController() : QObject(NULL)
{
    mTimer = new QTimer();    
    connect(mTimer, SIGNAL(timeout()), this, SLOT(handleTimeout()));
    mRefreshCount = 0;
}

RefreshController::~RefreshController()
{
    DELETE(mTimer);
}

void RefreshController::init()
{
    Setting setting = Setting::getSettingInfo();

    if (setting.getAutoRefresh())
    {
        refreshAll();
    }

    mTimer->start((int)(setting.getRefreshInterval() * 1000 * 60));
}

void RefreshController::setObserver(IRefreshControllerObserver *observer)
{
    mObserver = observer;
}

void RefreshController::updateRefreshSeting()
{
    Setting setting = Setting::getSettingInfo();

    if (setting.getAutoRefresh())
    {
        mTimer->start((int)(setting.getRefreshInterval() * 1000 * 60));
    }
    else
    {
        mTimer->stop();
    }
}

void RefreshController::refreshAll()
{
    mObserver->handleStartRefreshAll();

    QVector<Channel> channels = Channel::getAllChannels();
    for (int i = 0; i < channels.size(); ++i)
    {
        ChannelDownloader* downloader = new ChannelDownloader();
        downloader->setObserver(this);
        downloader->setChannelToDownload(channels.at(i));
        mDownloadQueue.append(downloader);
    }

    for (int i = 0; i < DOWNLOAD_LIMIT; ++i)
    {
        if (mDownloadQueue.empty())
        {
            break;
        }
        else
        {
            ChannelDownloader* downloader = mDownloadQueue.at(0);
            mDownloadQueue.pop_front();
            downloader->downloadChannelAsync();
            ++mRefreshCount;
        }
    }
}

void RefreshController::refresh(int channelId)
{
    ChannelDownloader* downloader = new ChannelDownloader();
    downloader->setObserver(this);
    downloader->setChannelToDownload(Channel::getChannel(channelId));
    downloader->downloadChannelAsync();
}

void RefreshController::handleStartDownload(int channelId)
{
    mObserver->handleStartRefresh(channelId);
}

void RefreshController::handleChannelDownloaded(int channelId, DownloadState downloadState, ChannelDownloader*downloaderToDelete)
{
    mObserver->handleChannelRefreshed(channelId, downloadState);
    DELETE(downloaderToDelete);

    --mRefreshCount;

    if (!mDownloadQueue.empty() && mRefreshCount < DOWNLOAD_LIMIT)
    {
        ChannelDownloader* downloader = mDownloadQueue.at(0);
        mDownloadQueue.pop_front();
        downloader->downloadChannelAsync();
        ++mRefreshCount;
    }
}

void RefreshController::handleTimeout()
{
    if (Setting::getSettingInfo().getAutoRefresh())
    {
        refreshAll();        
    }    
}
