#include "satellitedist.h"
#include "ui_satellitedist.h"

satellitedist::satellitedist(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::satellitedist)
{
    ui->setupUi(this);
}

satellitedist::~satellitedist()
{
    delete ui;
}
