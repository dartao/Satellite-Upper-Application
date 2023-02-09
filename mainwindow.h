#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QtSerialPort>
#include <QSerialPortInfo>
#include <dialog_connect.h>
#include <multicomtest.h>
#include <satedist.h>
#include <rdsscomm.h>
#include <channelinfo.h>
#include <maptrake.h>
#include <datashow.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_action_connect_triggered();

    void on_action_dataview_triggered();

    void on_action_exit_triggered();


    void on_action_multi_test_com_triggered();

    void on_action_satellite_dist_triggered();

    void on_action_Rdss_triggered();

    void on_action_channel_comm_triggered();

    void on_action_map_triggered();

    void on_action_reset_layout_triggered();

    void on_action_load_file_triggered();

    void on_action_about_triggered();

private:
    Ui::MainWindow *ui;

    Dialog_connect *dialog_connect;
    multicomtest *multitestcom;

    SateDist *satedist;
    RdssComm *rdsscomm;
    ChannelInfo *channelinfo;
    MapTrake *maptrake;
    DataShow *datashow;

    void system_init();//系统初始化函数

};

#endif // MAINWINDOW_H
