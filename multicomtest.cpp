#include "multicomtest.h"
#include "ui_multicomtest.h"

multicomtest::multicomtest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::multicomtest)
{
    ui->setupUi(this);
}

multicomtest::~multicomtest()
{
    delete ui;
}
