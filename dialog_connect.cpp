#include "dialog_connect.h"
#include "ui_dialog_connect.h"
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QDebug>
#include "extern_variable.h"


Dialog_connect::Dialog_connect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_connect)
{
    ui->setupUi(this);
    init();
}

Dialog_connect::~Dialog_connect()
{
    delete ui;
}

void Dialog_connect::init(){
    //调整窗口顶端的按钮
    Qt::WindowFlags flags=Qt::Dialog;
    flags |=Qt::WindowCloseButtonHint;
    flags |=Qt::WindowMaximizeButtonHint;
    flags |=Qt::WindowMaximizeButtonHint;
    setWindowFlags(flags);

    QStringList baudList;//波特率
    QStringList parityList;//校验位
    QStringList dataBitsList;//数据位
    QStringList stopBitsList;//停止位

    //波特率
    baudList<<"1200"<<"1800"<<"2400"<<"4800"<<"9600"
           <<"14400"<<"19200"<<"38400"<<"57600"
          <<"76800"<<"115200"<<"230400"<<"380400"<<"460800"<<"921600";
    ui->comboBox_baud->addItems(baudList);
    ui->comboBox_baud->setCurrentText(QString::number(9600));//默认波特率

    //校验位
    parityList<<"None"<<"Even"<<"Odd"<<"Mark";
    ui->comboBox_parity->addItems(parityList);
    ui->comboBox_parity->setCurrentText("Even");

    //数据位
    dataBitsList<<"8"<<"7"<<"6"<<"5";
    ui->comboBox_datebit->addItems(dataBitsList);
    ui->comboBox_datebit->setCurrentIndex(0);

    //停止位
    stopBitsList<<"1"<<"2";
    ui->comboBox_stopbit->addItems(stopBitsList);
    ui->comboBox_stopbit->setCurrentIndex(0);

    //串口
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        ui->comboBox_port0->addItem(info.portName());
    }

}

void Dialog_connect::on_pushButton_open_clicked()
{
    qDebug()<<"测试槽函数";
    //波特率
    int baud=ui->comboBox_baud->currentText().toInt();
    //校验位
    QSerialPort::Parity parity;
    if(ui->comboBox_parity->currentText()=="Even"){
        parity=QSerialPort::EvenParity;
    }else if(ui->comboBox_parity->currentText()=="Odd"){
        parity=QSerialPort::OddParity;
    }else if(ui->comboBox_parity->currentText()=="None"){
        parity=QSerialPort::NoParity;
    }else if(ui->comboBox_parity->currentText()=="Mark"){
        parity=QSerialPort::MarkParity;
    }
    //数据位
    QSerialPort::DataBits databits;
    if(ui->comboBox_datebit->currentText()=="8"){
        databits=QSerialPort::Data8;
    }else if(ui->comboBox_datebit->currentText()=="7"){
        databits=QSerialPort::Data7;
    }else if(ui->comboBox_datebit->currentText()=="6"){
        databits=QSerialPort::Data6;
    }else if(ui->comboBox_datebit->currentText()=="5"){
        databits=QSerialPort::Data5;
    }
    //停止位
    QSerialPort::StopBits stopbits;
    if(ui->comboBox_stopbit->currentText()=="1"){
        stopbits=QSerialPort::OneStop;
    }else if(ui->comboBox_stopbit->currentText()=="2"){
        stopbits=QSerialPort::TwoStop;
    }

    com_port0.setPortName(ui->comboBox_port0->currentText());

    com_port0.open(QIODevice::ReadWrite);//必须先打开串口才能设置下面的参数
    if(com_port0.isOpen()){
        qDebug()<<"串口已打开";
    }
    com_port0.setBaudRate(baud);
    com_port0.setParity(parity);
    com_port0.setDataBits(databits);
    com_port0.setStopBits(stopbits);
    com_port0.setFlowControl(QSerialPort::NoFlowControl);


    //    qDebug()<<baud<<com_port0.baudRate()<<com_port0.dataBits()<<databits; 测试串口是否正确


}

void Dialog_connect::on_pushButton_closeall_clicked()
{
    com_port0.close();
}


