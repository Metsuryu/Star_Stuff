#include "setroute.h"
#include "ui_setroute.h"
#include "location.h"
#include "QString"
#include "location_pushbutton.h"
#include "settings.h"
#include "initializer_list"
#include "initializer_lists.h"
#include "QSoundEffect"
#include "QSound"


SetRoute::SetRoute(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetRoute)
{
    ui->setupUi(this);

    energy_available = (energy*100)/energy_capacity;
    ui->BAREnergyAvailable->setValue(energy_available);
    visited_before_arr[1] = true;
    makemap();
    selected_location=current_sector;
    ui->LBCurrentLocationValue->setText("Sector " + QString::number(current_sector));

}

SetRoute::~SetRoute()
{
    delete ui;
}


bool not_enough_energy = false; //Can be set to true by mapinfo()
double energy_required_value = 0.0;

template <typename T> //Returns true if a value is in the initialized list.
bool is_in(const T& val, const std::initializer_list<T>& list)
{
    for (const auto& i : list) {
        if (val == i) {
            return true;
        }
    }
    return false;
}


//Creates Map//

void SetRoute::makemap()
{

    //**Matrix of buttons**//
    int counter = 1;
    for (int i=0; i<=matrixsize-1; i++)//Fill map
    {{for (int j=0;j<=matrixsize-1;j++)
            {
                lpb[i][j] = new location_PushButton;
                lpb[i][j]->setMaximumSize(bttnsz,bttnsz);
                lpb[i][j]->setMinimumSize(bttnsz,bttnsz);
                lpb[i][j]->setText(QString::number(counter));
                lpb[i][j]->loc.id_setval(counter);
                lpb[i][j]->loc.visitedbefore_setval(visited_before_arr[counter]);
                distance=abs(lpb[i][j]->loc.id_val()-current_sector); //Absolute distance from current location
                /* TODO: Calculate energy_required for each location.
                 * For now try to find a good value for "ener_cost",
                 * if it's not good enough, try something else.*/
                lpb[i][j]->loc.energy_required_setval((inventory_load+ener_cost)*distance);
                connect(lpb[i][j],SIGNAL(clicked()),this,SLOT(mapinfo()));
                ui->MapLayout->addWidget(lpb[i][j],i,j);
                lpb[i][j]->show();
                counter ++;
            }
        }}
//lpb[0][0]->loc.visitedbefore_setval(true);//Starting point was visited before.
}//makemap() end//



//Fills info frame about selected location.//

void SetRoute::mapinfo()
{

    for (int i=0; i<=matrixsize-1; i++)
    {{for (int j=0;j<=matrixsize-1;j++)
            {if(lpb[i][j] == sender())
                {
                    int lpb_id = lpb[i][j]->loc.id_val(); //Temp. variable for easier reading.
                    bool visited_before = lpb[i][j]->loc.visitedbefore_val();

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


                    selected_location = lpb_id;
                    ui->BTJumpToLocation->setText("Jump to\nsector " + QString::number(lpb_id));
                    ui->BAREnergyRequired->setValue(energy_required);
                    if(visited_before){ui->LBVisitedBeforeValue->setText("Yes");}
                    else if(!visited_before){ui->LBVisitedBeforeValue->setText("No");}

                    //**Assign loc_event to selected location**//
                    if(is_in(lpb_id,{SPACE_STATIONS_LIST})) {loc_event=location_event::SPACE_STATION;}
                    else if(is_in(lpb_id,{ASTEROIDS_LIST})) {loc_event=location_event::ASTEROID;}
                    else if(is_in(lpb_id,{ENEMIES_LIST})) {loc_event=location_event::ENEMY_SHIP;}
                    else if(is_in(lpb_id,{FRIENDS_LIST})) {loc_event=location_event::FRIENDLY_SHIP;}
                    else if(is_in(lpb_id,{PLANETS_LIST})) {loc_event=location_event::PLANET;}
                    else if(is_in(lpb_id,{STARS_LIST})) {loc_event=location_event::STAR;}
                    else if(is_in(lpb_id,{59})) {loc_event=location_event::BOSS1;}
                    else if(is_in(lpb_id,{69})) {loc_event=location_event::BOSS2;}
                    else if(is_in(lpb_id,{79})) {loc_event=location_event::BOSS3;}
                    else if(is_in(lpb_id,{89})) {loc_event=location_event::BOSS4;}
                    else if(is_in(lpb_id,{100})) {loc_event=location_event::FINAL_BOSS;}
                    //else if(//Something) {loc_event=location_event::QUEST;} TODO: Complete when quests are implemented
                    //**Special case when "nemesis" is true**//
                    //else if(nemesis && is_in(lpb_id,{SPACE_STATIONS_LIST,FRIENDS_LIST})) {loc_event=location_event::COMMERCE_SHIP;}//TODO: Complete when implementing "nemesis"

                }//TODO: Complete info
            }
        }
    }
}//mapinfo() end//


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


//Jumps to selected destination//
void SetRoute::on_BTJumpToLocation_clicked()
{
    if(not_enough_energy){not_enough_energy_message(); return;}
    if(selected_location==current_sector){already_here_message(); return;}
    //**JUMP**//

    energy=energy-energy_required_value;
    ui->BAREnergyAvailable->setValue(energy);
    current_sector=selected_location;

    for (int i=0; i<=matrixsize-1; i++)
    {{for (int j=0;j<=matrixsize-1;j++)
            {if(lpb[i][j]->loc.id_val() == selected_location)
                {qDebug() << selected_location; visited_before_arr[selected_location]=true; break;}}}}

    //**sfx warp**//  //TODO: Use Phonon for sound effects and music
    if(sfx_enabled)
    {
    QSoundEffect *se_warp = new QSoundEffect();//Can't set "this" as parent, or it will be deleted before it plays.
    se_warp->setSource(QUrl("qrc:/sfx/sfx/Warp sound.wav"));
    //sfx_volume = volume; //Doesn't work. Alters value of volume. It's a bug of Qt: https://bugreports.qt.io/browse/QTBUG-43765
    se_warp->setVolume(0.30f); //TODO: Set variable for volume of sfx sounds when Qt bug is fixed.
    se_warp->play();

    }
    //**sfx warp**//

    switch (loc_event)//TODO: Write function for each case. TODO: Play sound and have option to disable sfx
    {
    case location_event::ENEMY_SHIP:
        qDebug() << "Enemy Ship";
        break;
    case location_event::SPACE_STATION:
        qDebug() << "Space station";
        break;
    case location_event::ASTEROID:
        qDebug() << "Asteroid";
        break;
    case location_event::FRIENDLY_SHIP:
        qDebug() << "Friendly Ship";
        break;
    case location_event::PLANET:
        qDebug() << "Planet";
        break;
    case location_event::STAR:
        qDebug() << "Star";
        break;
    case location_event::BOSS1:
        qDebug() << "Boss 1";
        break;
    case location_event::BOSS2:
        qDebug() << "Boss 2";
        break;
    case location_event::BOSS3:
        qDebug() << "Boss 3";
        break;
    case location_event::BOSS4:
        qDebug() << "Boss 4";
        break;
    case location_event::FINAL_BOSS:
        qDebug() << "Final Boss";
        break;
    case location_event::COMMERCE_SHIP:
        qDebug() << "Commerce ship";
        break;
        //TODO: Add QUEST case when implementing quests
    default:
        //Should never reach default.
        error_generic();//TODO: Write better errors
        break;
    }


    //TODO: Some animation or something to show you jumped
    SetRoute::close();
}//JUMP//

void SetRoute::on_BTCancel_clicked()
{
    loc_event=location_event::NO_JUMP;
    SetRoute::close();
}

void SetRoute::on_BTAdditionalInfo_clicked()//TODO: Open additional info dialog.
{
    qDebug() << "Full energy.";
    energy=energy_capacity;//TODO: Remove this when not needed anymore for debug.
}
