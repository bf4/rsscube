// 2009-07-07 裴小星 创建框架

#include "ChannelDownloader.h"

ChannelDownloader::ChannelDownloader(bool writeDb) : mWriteDb(writeDb)
{
}

ChannelDownloader::~ChannelDownloader()
{
}

void ChannelDownloader::setObserver(IChannelDownloaderObserver *observer)
{
}

void ChannelDownloader::downloadChannelAsync(int channelId)
{
}

void ChannelDownloader::httpDownloaded()
{
}

void ChannelDownloader::httpTimeout()
{
}
