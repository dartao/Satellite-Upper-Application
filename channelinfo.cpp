#include "channelinfo.h"
#include "ui_channelinfo.h"
#include <QVBoxLayout>

ChannelInfo::ChannelInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChannelInfo)
{
    ui->setupUi(this);
}

ChannelInfo::~ChannelInfo()
{
    delete ui;
}
