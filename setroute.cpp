#include "setroute.h"
#include "ui_setroute.h"
#include "location.h"
#include "location.cpp"
#include "QString"

SetRoute::SetRoute(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetRoute)
{
    ui->setupUi(this);
    makemap();
}

SetRoute::~SetRoute()
{
    delete ui;
}


//Makes a map to choose a location to travel to.


//********************Creating Map********************//

void SetRoute::makemap()//TODO: Buttons do nothing for now, add functionality to buttons.
{

    //********************Matrix of buttons***************************//

    //QPushButton *mapbutton[matrixsize][matrixsize]; //This is in the header.
    int counter = 1;
    for (int i=0; i<=matrixsize-1; i++)//Fill map
    {{for (int j=0;j<=matrixsize-1;j++)
            {
                mapbutton[i][j] = new QPushButton("p",ui->MapFrame);
                mapbutton[i][j]->setMaximumSize(bttnsz,bttnsz);
                mapbutton[i][j]->setMinimumSize(bttnsz,bttnsz);
                mapbutton[i][j]->setText(QString::number(counter));
                connect(mapbutton[i][j],SIGNAL(released()),this,SLOT(mapinfo()));
                ui->MapLayout->addWidget(mapbutton[i][j],i,j);
                mapbutton[i][j]->show();
                counter ++;
            }
        }}
}
//********************Map Created*************************************//


//Make function to fill values of map

void SetRoute::mapinfo() //TODO: Remove this test code and show actual informations for each location
{
    //energy_required=42; //% Of energy required
    //ui->BAREnergyRequired->setValue(energy_required);
    //ui->BAREnergyAvailable->setValue(energy_available);
}

