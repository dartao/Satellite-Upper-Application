#include "rdsscomm.h"
#include "ui_rdsscomm.h"

RdssComm::RdssComm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RdssComm)
{
    ui->setupUi(this);
}

RdssComm::~RdssComm()
{
    delete ui;
}
