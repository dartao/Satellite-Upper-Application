#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "dialog_connect.h"
#include "extern_variable.h"
#include "multicomtest.h"
#include "QMdiSubWindow"
#include <QFileDialog>
#include <QString>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    setCentralWidget(ui->mdiArea);

    showMaximized();

    system_init();  //系统初始化


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::system_init(){

    //类对象初始化
     dialog_connect = new Dialog_connect();
    //view_data dataview(this);
    datashow = new DataShow();
    multitestcom = new multicomtest();
    satedist = new SateDist();
    rdsscomm = new RdssComm();
    channelinfo = new ChannelInfo();
    maptrake = new MapTrake();

}

void MainWindow::on_action_connect_triggered()
{
    dialog_connect->show();
}


void MainWindow::on_action_dataview_triggered()
{
    bool isOpen = false;
    for (int i=0;i<ui->mdiArea->subWindowList().size();i++) {
        QMdiSubWindow *subwin = ui->mdiArea->subWindowList().at(i);

        if(subwin->windowTitle() == "数据会话视图"){
            datashow->show();
            isOpen = true;
            break;
        }
    }
    if(isOpen == false){

        QMdiSubWindow *datashowWindow = new QMdiSubWindow;
        datashowWindow->setWidget(datashow);
        ui->mdiArea->addSubWindow(datashowWindow);
        datashow->show();
    }
}


void MainWindow::on_action_exit_triggered()
{

}


void MainWindow::on_action_multi_test_com_triggered()
{
    // qDebug()<<"批量测试";
    bool isOpen = false;
    // qDebug()<<ui->mdiArea->subWindowList().size();
    for (int i=0;i<ui->mdiArea->subWindowList().size();i++) {
        QMdiSubWindow *subwin = ui->mdiArea->subWindowList().at(i);
        // qDebug()<<subwin->windowTitle()<<"s";

        if(subwin->windowTitle() == "批量测试串口"){
            //ui->mdiArea->setActiveSubWindow(subwin);
            multitestcom->show();
            isOpen = true;
            break;
        }
    }
    if(isOpen == false){

        QMdiSubWindow *multitestcomWindow = new QMdiSubWindow;
        multitestcomWindow->setWidget(multitestcom);
        ui->mdiArea->addSubWindow(multitestcomWindow);
        multitestcom->show();
    }

}

void MainWindow::on_action_satellite_dist_triggered()
{
    bool isOpen = false;
    // qDebug()<<ui->mdiArea->subWindowList().size();
    for (int i=0;i<ui->mdiArea->subWindowList().size();i++) {
        QMdiSubWindow *subwin = ui->mdiArea->subWindowList().at(i);
        // qDebug()<<subwin->windowTitle()<<"s";

        if(subwin->windowTitle() == "卫星分布视图"){
            //ui->mdiArea->setActiveSubWindow(subwin);
            satedist->show();
            isOpen = true;
            break;
        }
    }
    if(isOpen == false){

        QMdiSubWindow *satedistWindow = new QMdiSubWindow;
        satedistWindow->setWidget(satedist);
        ui->mdiArea->addSubWindow(satedistWindow);
        satedist->show();
    }
}

void MainWindow::on_action_Rdss_triggered()
{
    bool isOpen = false;
    // qDebug()<<ui->mdiArea->subWindowList().size();
    for (int i=0;i<ui->mdiArea->subWindowList().size();i++) {
        QMdiSubWindow *subwin = ui->mdiArea->subWindowList().at(i);
        // qDebug()<<subwin->windowTitle()<<"s";

        if(subwin->windowTitle() == "Rdss通信视图"){
            //ui->mdiArea->setActiveSubWindow(subwin);
            rdsscomm->show();
            isOpen = true;
            break;
        }
    }
    if(isOpen == false){

        QMdiSubWindow *rdsscommWindow = new QMdiSubWindow;
        rdsscommWindow->setWidget(rdsscomm);
        ui->mdiArea->addSubWindow(rdsscommWindow);
        rdsscomm->show();
    }
}

void MainWindow::on_action_channel_comm_triggered()
{
    bool isOpen = false;
    for (int i=0;i<ui->mdiArea->subWindowList().size();i++) {
        QMdiSubWindow *subwin = ui->mdiArea->subWindowList().at(i);

        if(subwin->windowTitle() == "通道信息视图"){
            channelinfo->show();
            isOpen = true;
            break;
        }
    }
    if(isOpen == false){

        QMdiSubWindow *channelinfoWindow = new QMdiSubWindow;
        channelinfoWindow->setWidget(channelinfo);
        ui->mdiArea->addSubWindow(channelinfoWindow);
        channelinfo->show();
    }
}

void MainWindow::on_action_map_triggered()
{
    bool isOpen = false;
    for (int i=0;i<ui->mdiArea->subWindowList().size();i++) {
        QMdiSubWindow *subwin = ui->mdiArea->subWindowList().at(i);

        if(subwin->windowTitle() == "地图追踪视图"){
            maptrake->show();
            isOpen = true;
            break;
        }
    }
    if(isOpen == false){

        QMdiSubWindow *maptrakeWindow = new QMdiSubWindow;
        maptrakeWindow->setWidget(maptrake);
        ui->mdiArea->addSubWindow(maptrakeWindow);
        maptrake->show();
    }
}

void MainWindow::on_action_reset_layout_triggered()
{

    ui->mdiArea->tileSubWindows();

}

void MainWindow::on_action_load_file_triggered()
{
    QString path = QFileDialog::getOpenFileName(
                this,
                "打开回放文件",
                "../"
                );
    qDebug()<<path;
}

void MainWindow::on_action_about_triggered()
{

    QMessageBox::about(this,"关于我们","有任何问题请联系邮箱! ");

}
