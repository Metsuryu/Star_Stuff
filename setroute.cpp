#include "setroute.h"
#include "ui_setroute.h"
#include "location.h"
#include "iostream"
#include "location.cpp"

SetRoute::SetRoute(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetRoute)
{
    ui->setupUi(this);
    makemap();
    ui->BAREnergyRequired->setValue(energyrequired);
    //connect(mapbutton[1][1],SIGNAL(released()),this,SLOT(mapinfo()));
}

SetRoute::~SetRoute()
{
    delete ui;
}


//Make a map to choose a location to travel to.


//********************Creating Map********************//

void SetRoute::makemap(){ //TODO: Buttons do nothing for now, add functionality to buttons.

    //********************Matrix of buttons***************************//

    //QPushButton *mapbutton[matrixsize][matrixsize];

    for (int i=0; i<=matrixsize-1; i++)//Fill map
    {{for (int j=0;j<=matrixsize-1;j++)
            {
                mapbutton[i][j] = new QPushButton("p",ui->MapFrame);
                mapbutton[i][j]->setMaximumSize(bttnsz,bttnsz);
                mapbutton[i][j]->setMinimumSize(bttnsz,bttnsz);
                connect(mapbutton[i][j],SIGNAL(released()),this,SLOT(mapinfo()));
                ui->MapLayout->addWidget(mapbutton[i][j],i,j);
                mapbutton[i][j]->show();
            }
        }}
}
//********************Map Created*************************************//

//Make function to fill values of map



void SetRoute::mapinfo() //TODO: Remove test code and show actual informations for each location
{
    energyrequired=42; //% Of energy required
    ui->BAREnergyRequired->setValue(energyrequired);
    //***//
    using namespace std;
    cout << loc->id_val()<<loc->energy_required_val()<<loc->quest_val()<<loc->visitedbefore_val()<<"\n";
    cout << loc1->id_val()<<loc1->energy_required_val()<<loc1->quest_val()<<loc1->visitedbefore_val()<<"\n";

}

