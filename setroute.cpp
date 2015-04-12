#include "setroute.h"
#include "ui_setroute.h"

SetRoute::SetRoute(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetRoute)
{
    ui->setupUi(this);
}

SetRoute::~SetRoute()
{
    delete ui;
}
