// 2009-07-07 裴小星 创建框架

#ifndef INTERFACES_H
#define INTERFACES_H

#include "enums.h"

class ChannelDownloader;

class IChannelDownloaderObserver
{

public:
    virtual ~IChannelDownloaderObserver();
    virtual void handleChannelDownloaded(int channelId, DownloadState downloadState, ChannelDownloader* downloaderToDelete) = 0;
};

class IRefreshControllerObserver
{

public:
    virtual ~IRefreshControllerObserver();
    virtual void handleChannelRefreshed(int channelId, DownloadState downloadState);
};

class ISettingControllerObserver
{

public:
    virtual ~ISettingControllerObserver();
    virtual void handleDisplaySettingChanged(ReadType readType);
};

#endif // INTERFACES_H
