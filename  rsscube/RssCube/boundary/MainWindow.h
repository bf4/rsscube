#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include "../other/interfaces.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow, public IChannelDownloaderObserver
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void handleStartDownload(int channelId);

    void handleChannelDownloaded(int channelId, DownloadState downloadState,
                            ChannelDownloader* downloaderToDelete);

    int add();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
