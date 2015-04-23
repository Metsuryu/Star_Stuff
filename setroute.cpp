#include "setroute.h"
#include "ui_setroute.h"
#include "location.h"
#include "location.cpp"
#include "QString"
#include "location_pushbutton.h"

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

/*  TODO: ENABLE TO CREATE MAP.
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
        }}*/

    //int i = 0;
    //int j = 0;
    lpb[0][0] = new location_PushButton;
    lpb[0][1] = new location_PushButton;
    ui->MapLayout->addWidget(lpb[0][0]);
    ui->MapLayout->addWidget(lpb[0][1]);
    lpb[0][0]->setText("22");
    lpb[0][1]->setText("53");
    lpb[0][0]->loc.id_setval(22);
    lpb[0][1]->loc.id_setval(53);
    //connect(lpb[0][0],SIGNAL(released()),this,SLOT(mapinfo())); TODO: Try to give an id to the signal with qtsignalmapper
    //j=1;
    //connect(lpb[0][1],SIGNAL(released()),this,SLOT(mapinfo(i,j)));

    lpb[0][0]->show();
    lpb[0][1]->show();

    /*mapbutton[i][j] = new QPushButton("p",ui->MapFrame);
    mapbutton[i][j]->setMaximumSize(bttnsz,bttnsz);
    mapbutton[i][j]->setMinimumSize(bttnsz,bttnsz);
    mapbutton[i][j]->setText(QString::number(1));
    connect(mapbutton[i][j],SIGNAL(released()),this,SLOT(mapinfo()));
    ui->MapLayout->addWidget(mapbutton[i][j],i,j);
    mapbutton[i][j]->show();
*/



}
//********************Map Created*************************************//


//Make function to fill values of map

void SetRoute::mapinfo() //TODO: Remove this test code and show actual informations for each location
{

    ui->BAREnergyRequired->setValue(64);

    //energy_required=42; //% Of energy required
    //ui->BAREnergyRequired->setValue(energy_required);
    //ui->BAREnergyAvailable->setValue(energy_available);
}

