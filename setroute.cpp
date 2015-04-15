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


//Make a map to choose a location to travel to, and a button to go to a random location.
//Map Locations have better stuff than random ones.
