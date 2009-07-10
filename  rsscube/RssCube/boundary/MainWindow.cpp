#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "../entity/ChannelDownloader.h"
#include "../other/macros.h"
#include <QLabel>
#include <QSqlDatabase>
#include "../control/DatabaseController.h"
#include "../control/RefreshController.h"
#include "../control/ChannelController.h"
#include "../control/SettingController.h"
#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*
    ui->setupUi(this);
    DatabaseController db=DatabaseController::getInstance();
    db.connect("rss_cube.db");
    ChannelDownloader *loader=new ChannelDownloader(false);
    loader->setObserver(this);
    //Channel channel=Channel::getChannel(1);
    //loader->setChannelToDownload(channel);
    //loader->downloadChannelAsync();
    loader->checkUrlAsync("http://www.people.com.cn/rss/finance.xml");
    */
    /*
    ui->setupUi(this);
    DatabaseController db=DatabaseController::getInstance();
    db.connect("rss_cube.db");

    RefreshController & fresher = RefreshController::getInstance();
    fresher.setObserver(this);
    fresher.init();
    SettingController::getInstance().changeRreshSetting(true,1);
    */
/*
    ui->setupUi(this);
    DatabaseController db = DatabaseController::getInstance();
    db.connect();

    ChannelController & controller = ChannelController::getInstance();
    controller.setObserver(this);
    controller.checkUrl("http://www.people.com.cn/rss/finance.xml");
*/
  // fresher.refreshAll();
}

MainWindow::~MainWindow()
{
    delete ui;
}
/*
void MainWindow::handleUrlChecked(DownloadState downloadState)
{
    QString str="";
    if(downloadState==DS_Success)
       str=QString("sucess");
    else if(downloadState==DS_Timeout)
       str=QString("timeout");
    else
       str=QString("format error");

   QLabel *label = new QLabel();
   label->setText(str);
   label->show();
}*/

/*
void MainWindow::handleStartDownload(int channelId)
{
    ui->lblStart->setText("start. id: " + channelId);
}
*/
/*
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
*/

/*
void MainWindow::handleStartRefresh(int channelId)
{
   QLabel *label = new QLabel();
   label->setText(QString("start. id:") + QString::number(channelId));
   label->show();
}
void MainWindow::handleChannelRefreshed(int channelId,DownloadState downloadState)
{
    QString str="";
    if(downloadState==DS_Success)
       str=QString("sucess channelId: ")+QString::number(channelId);
    else if(downloadState==DS_Timeout)
       str=QString("timeout channelId: ")+QString::number(channelId);
    else
        str=QString("format error channelId: ")+QString::number(channelId);

   QLabel *label = new QLabel();
   label->setText(str);
   label->show();
}
void MainWindow::handleStartRefreshAll()
{
   QLabel *label = new QLabel();
   label->setText(QString("refresh all") );
   label->show();
}
*/

