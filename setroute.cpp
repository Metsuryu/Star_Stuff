#include "setroute.h"
#include "ui_setroute.h"
#include "location.h"
#include "location.cpp"
#include "QString"
#include "location_pushbutton.h"
#include "settings.h"


SetRoute::SetRoute(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetRoute)
{
    ui->setupUi(this);
    energy_available = (energy*100)/energy_capacity;
    ui->BAREnergyAvailable->setValue(energy_available);
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

//** Enable to create map of normal pushbuttons **//
    //DO NOT ENABLE while other matrix is enabled
/*
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
*/
//********************************************************************************//

    int counter = 1;
    for (int i=0; i<=matrixsize-1; i++)//Fill map
    {{for (int j=0;j<=matrixsize-1;j++)
            {
                lpb[i][j] = new location_PushButton;//("p",ui->MapFrame);
                lpb[i][j]->setMaximumSize(bttnsz,bttnsz);
                lpb[i][j]->setMinimumSize(bttnsz,bttnsz);
                lpb[i][j]->setText(QString::number(counter));
                lpb[i][j]->loc.id_setval(counter);
                distance=abs(lpb[i][j]->loc.id_val()-current_sector);
                lpb[i][j]->loc.energy_required_setval((inventory_load+ener_cost)*distance);//TODO: Calculate energy_required for each location
                connect(lpb[i][j],SIGNAL(released()),this,SLOT(mapinfo()));
                ui->MapLayout->addWidget(lpb[i][j],i,j);
                lpb[i][j]->show();
                counter ++;
            }
        }}
}//********************makemap() end******************//



//Make function to fill values of map

void SetRoute::mapinfo() //TODO: Remove this test code and show actual informations for each location
{
/*    if(lpb[0][0] == sender())
    {ui->BAREnergyRequired->setValue(lpb[0][0]->loc.energy_required_val());}
    else if(lpb[0][1] == sender())
    {ui->BAREnergyRequired->setValue(lpb[0][1]->loc.energy_required_val());}
*/

    for (int i=0; i<=matrixsize-1; i++)
    {{for (int j=0;j<=matrixsize-1;j++)
            {if(lpb[i][j] == sender())
                {
                    energy_required=(lpb[i][j]->loc.energy_required_val()*100)/energy_available;
                    if(energy_required>energy_available){not_enough_energy_message();}
                    ui->BTJumpToLocation->setText("Jump to\nsector " + QString::number(lpb[i][j]->loc.id_val()));
                    ui->BAREnergyRequired->setValue(energy_required);

                    //TODO: Complete info
                }//end block of if
            }//end if
        }//end for j
    }//end for i

    //energy_required=42; //% Of energy required
    //ui->BAREnergyRequired->setValue(energy_required);
    //ui->BAREnergyAvailable->setValue(energy_available);

}

void not_enough_energy_message()
{
QMessageBox nnem;
nnem.setText("Not enough energy to jump to this destination.");
nnem.setInformativeText("Please select another destination.");
nnem.setWindowTitle("Not enough energy");
nnem.setStandardButtons(QMessageBox::Ok);
nnem.exec();
}
