#include "maptrake.h"
#include "ui_maptrake.h"

MapTrake::MapTrake(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MapTrake)
{
    ui->setupUi(this);
}

MapTrake::~MapTrake()
{
    delete ui;
}
