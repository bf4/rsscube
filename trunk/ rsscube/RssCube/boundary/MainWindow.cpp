#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "../entity/ChannelDownloader.h"
#include "../other/macros.h"
#include <QSqlDatabase>
#include "../control/DatabaseController.h"
#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    DatabaseController db=DatabaseController::getInstance();
    db.connect("rss_cube.db");
    ChannelDownloader *loader=new ChannelDownloader(false);
    loader->setObserver(this);
    //Channel channel=Channel::getChannel(1);
    //loader->setChannelToDownload(channel);
    //loader->downloadChannelAsync();
    loader->checkUrlAsync("http://www.people.com.cn/rss/finance.xml");
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::add()
{
    return 0;
}
void MainWindow::handleStartDownload(int channelId)
{
    ui->lblStart->setText("start. id: " + channelId);

}

void MainWindow::handleChannelDownloaded(int channelId,DownloadState downloadState,
                                           ChannelDownloader *downloaderToDelete)
{
    //cout<<channelId<<endl;
    if(downloadState==DS_Success)
    {
         ui->lblStart->setText("completed. id: " + channelId);
    }
    else if(downloadState==DS_Timeout)
    {
         ui->lblStart->setText("timeout. id: " + channelId);
    }
    else
    {
         ui->lblStart->setText("format error. id: " + channelId);
    }
    DELETE(downloaderToDelete);
}

