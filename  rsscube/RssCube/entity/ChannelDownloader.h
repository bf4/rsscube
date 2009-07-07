// 2009-07-07 裴小星 创建框架

#ifndef CHANNELDOWNLOADER_H
#define CHANNELDOWNLOADER_H

#include <QHttp>
#include <QBuffer>
#include <QTimer>
#include "../other/interfaces.h"
#include "../entity/Channel.h"

class ChannelDownloader
{

public:
    ChannelDownloader(bool writeDb = true);
    ~ChannelDownloader();
    void setObserver(IChannelDownloaderObserver* observer);
    void downloadChannelAsync(int id);
    void httpDownloaded();
    void httpTimeout();

private:

    QHttp* mHttp;
    QBuffer* mBuffer;
    Channel* mChannel;
    QTimer mTimer;
    bool mWriteDb;
    IChannelDownloaderObserver* mObserver;
};

#endif // CHANNELDOWNLOADER_H
