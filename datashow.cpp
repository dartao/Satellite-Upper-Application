#include "datashow.h"
#include "ui_datashow.h"

DataShow::DataShow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataShow)
{
    ui->setupUi(this);
}

DataShow::~DataShow()
{
    delete ui;
}
