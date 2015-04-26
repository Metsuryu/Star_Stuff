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
    selected_location=current_sector;
    ui->LBCurrentLocationValue->setText("Sector " + QString::number(current_sector));
}

SetRoute::~SetRoute()
{
    delete ui;
}

bool not_enough_energy = false;
double energy_required_value = 0.0;



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

    for (int i=0; i<=matrixsize-1; i++)
    {{for (int j=0;j<=matrixsize-1;j++)
            {if(lpb[i][j] == sender())
                {
                    energy_required=(lpb[i][j]->loc.energy_required_val()*100)/energy_available; //Set energy_required value in %
                    energy_required_value=lpb[i][j]->loc.energy_required_val();
                    ui->BAREnergyRequired->setStyleSheet(greenbar);
                    ui->BAREnergyRequired->setRange(0,100);
                    not_enough_energy = false;

                    if(lpb[i][j]->loc.energy_required_val()>energy_available)//Not enough energy
                    {
                        not_enough_energy = true;
                        ui->BAREnergyRequired->setRange(0,energy_required); //TODO: Check that this works with energy_capacity values above 100
                        ui->BAREnergyRequired->setStyleSheet(redbar);

                    }

                    selected_location = lpb[i][j]->loc.id_val();
                    ui->BTJumpToLocation->setText("Jump to\nsector " + QString::number(lpb[i][j]->loc.id_val()));
                    ui->BAREnergyRequired->setValue(energy_required);


                }//TODO: Complete info
            }
        }
    }
}

void not_enough_energy_message()//TODO: Maybe play warning sound
{
    QMessageBox nnem;
    nnem.setText("Not enough energy to jump to this destination.");
    nnem.setInformativeText("Please select another destination.");
    nnem.setWindowTitle("Not enough energy");
    nnem.setStandardButtons(QMessageBox::Ok);
    nnem.setDefaultButton(QMessageBox::Ok);
    nnem.setIcon(QMessageBox::Information);
    nnem.exec();
}

void already_here_message()//TODO: Maybe play warning sound
{
    QMessageBox ah;
    ah.setText("This is your current location.");
    ah.setInformativeText("Please select another destination.");
    ah.setWindowTitle("You are already here.");
    ah.setStandardButtons(QMessageBox::Ok);
    ah.setDefaultButton(QMessageBox::Ok);
    ah.setIcon(QMessageBox::Information);
    ah.exec();
}




void SetRoute::on_BTJumpToLocation_clicked()
{
    if(not_enough_energy){not_enough_energy_message(); return;}
    if(selected_location==current_sector){already_here_message(); return;}
    //**JUMP**//
    energy=energy-energy_required_value;
    ui->BAREnergyAvailable->setValue(energy);
    current_sector=selected_location;

    switch (loc_event)//TODO: Write function for each case. TODO: Assign correct value to loc_event for each location
    {
    case location_event::ASTEROID:
        break;
    case location_event::ENEMY_SHIP:
        break;
    case location_event::FRIENDLY_SHIP:
        break;
    case location_event::COMMERCE_SHIP:
        break;
    case location_event::PLANET:
        break;
    case location_event::STAR:
        break;
    case location_event::SPACE_STATION:

        break;

    default:
        //Should never reach default.
        error_generic();
        break;
    }


//TODO: Some animation or something to show you jumped
SetRoute::close();
}

void SetRoute::on_BTCancel_clicked()
{
    SetRoute::close();
}
