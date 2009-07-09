// 2009-07-07 裴小星 创建框架
// 2009-07-07 裴小星 添加注释

#ifndef INTERFACES_H
#define INTERFACES_H

#include "enums.h"

class ChannelDownloader;

class IChannelDownloaderObserver
{

public:
    virtual ~IChannelDownloaderObserver() {}

    /**
      When start to download the channel,
      the observer will be notified.
      */
    virtual void handleStartDownload(int channelId) = 0;

    /**
      When the downloader compelete to download a channel,
      the observer will be notified.
      This function is used to handle this event.
      @param channelId
      The id of the channel to download.
      @param downloadState
      The downloadState (Success, Timeout, RssFomatError).
      @param downloaderToDelete
      The downloader to delete
      */
    virtual void handleChannelDownloaded(int channelId, DownloadState downloadState, ChannelDownloader* downloaderToDelete) = 0;
};

class IChannelControllerObserver
{

public:
    virtual ~IChannelControllerObserver() {}

    /**
      When the channel controller compelete to check the url,
      the observer will be notified.
      This function is used to handle this event.
      @param downloadState
      The downloadState (Success, Timeout, RssFomatError).
      */
    virtual void handleUrlChecked(DownloadState downloadState) = 0;
};

class IRefreshControllerObserver
{

public:
    virtual ~IRefreshControllerObserver() {}

    /**
      When start to refresh the channel,
      the observer will be notified.
      @param channelId
      The id of the channel to refresh.
      */
    virtual void handleStartRefresh(int channelId) = 0;

    /**
      When the channel refreshed, the observer will be notified.
      This function is used to handle this event.
      @param channelId
      The id of the channel refreshed.
      @param downloadState
      The download state(Success, DS_Timeout, DS_RssFormatError).
      */
    virtual void handleChannelRefreshed(int channelId, DownloadState downloadState) = 0;
};

class ISettingControllerObserver
{

public:
    virtual ~ISettingControllerObserver() {}

    /**
      When the display setting is changed, the observer will be notified.
      This funtion will used to handle this event.
      @param readType
      The read type (All, Read, Unread).
      */
    virtual void handleDisplaySettingChanged(ReadType readType) = 0;
};

#endif // INTERFACES_H
