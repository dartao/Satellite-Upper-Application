#include "satedist.h"
#include "ui_satedist.h"

SateDist::SateDist(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SateDist)
{
    ui->setupUi(this);
}

SateDist::~SateDist()
{
    delete ui;
}
