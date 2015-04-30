#include "maingame.h"
#include "ui_maingame.h"
#include "settings.h"
#include "setroute.h"
#include "QMessageBox"


MainGame::MainGame(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainGame)
{
    ui->setupUi(this);
    ui->BAREnergy->setValue(energy);
    ui->BARHull->setValue(hull);
    ui->LBLocation->setText("Sector "+ QString::number(current_sector));

}

MainGame::~MainGame()
{
    delete ui;
}

//**Pixmap strings**//
QString space_station_pm = ":/pics/img/SpaceStation 383.jpg";
QString space_station_ss = "background-color: rgb(113, 113, 113);";
QString asteroid_pm = ":/pics/img/Spaceship stars 200px.jpg";
QString asteroid_ss = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 10, 95, 255), stop:1 rgba(0, 10, 95, 255));";

//****//


//TODO: option to confirm quit

void MainGame::closeEvent(QCloseEvent *event) //Asks the user for confirmation to quit.
{   
    event->ignore();
    if(quit_confirm)
    {
    QMessageBox unsaved_alert;
    unsaved_alert.setText("Are you sure you want to quit?");
    unsaved_alert.setInformativeText("Do you want to save your progress or discard all changes and quit?");
    unsaved_alert.setWindowTitle("Are you sure?");
    unsaved_alert.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    unsaved_alert.setIcon(QMessageBox::Question);
    int saveprompt = unsaved_alert.exec();

    switch (saveprompt)
    {
      case QMessageBox::Save:
          // TODO: Add save function
          break;
      case QMessageBox::Discard:
          QApplication::quit();
          break;
      case QMessageBox::Cancel:
          // Close prompt.
          break;
      default:
          break;
    }
    }else{QApplication::quit();}
}



void MainGame::on_actionQuit_triggered()
{
    //closeEvent();
    //check if saved
    QApplication::quit(); //Quit without asking for now. TODO: Ask before quitting.
}

void MainGame::on_actionSettings_triggered()
{
    Settings settings;
    settings.setModal(true);
    settings.exec();
}

void MainGame::on_BTSetRoute_clicked()
{
    SetRoute setroute;
    setroute.setModal(true);
    setroute.exec();

    ui->BAREnergy->setValue(energy);
    ui->LBLocation->setText("Sector "+ QString::number(current_sector));
    jump();

}



void MainGame::jump()
{                     //TODO: Make graphic effects last as long as the sound effect
    switch (loc_event)//TODO: Write function for each case. TODO: Change grapics for each location
    {
    case location_event::SPACE_STATION:
        ui->Graphics->setPixmap(QPixmap(space_station_pm));
        ui->Graphics->setStyleSheet(space_station_ss);
        ui->textBrowser->append("The ship picks up an automated message from the space station:\n\"Welcome to Space Station \"" + QString::number(current_sector));//TODO: Replace space station number with a unique name.
        break;
    case location_event::ASTEROID:
        ui->Graphics->setPixmap(QPixmap(asteroid_pm));
        ui->Graphics->setStyleSheet(asteroid_ss);
        ui->textBrowser->append("You detect an asteroid field. Asteroids can be mined for valuable minerals.");
        //ui->textBrowser->append("What are your orders? 1: Do something. 2: Do something else. etc...");
        break;
    case location_event::ENEMY_SHIP:
        ui->textBrowser->append("Enemy ship.");
        break;
    case location_event::FRIENDLY_SHIP:
        ui->textBrowser->append("Friendly ship.");
        break;
    case location_event::PLANET:
        ui->textBrowser->append("Planet.");
        break;
    case location_event::STAR:
        ui->textBrowser->append("Star.");
        break;
    case location_event::BOSS1:
        qDebug() << "Boss 1 graphics";
        break;
    case location_event::BOSS2:
        qDebug() << "Boss 2 graphics";
        break;
    case location_event::BOSS3:
        qDebug() << "Boss 3 graphics";
        break;
    case location_event::BOSS4:
        qDebug() << "Boss 4 graphics";
        break;
    case location_event::FINAL_BOSS:
        qDebug() << "Final Boss graphics";
        break;
    case location_event::COMMERCE_SHIP:
        qDebug() << "Commerce ship graphics";
        break;
    case location_event::NO_JUMP:
        qDebug() << "No Jump";
        return;
        break;
        //TODO: Add QUEST case when implementing quests
    default:
        //Should never reach default.
        error_generic();//TODO: Write better errors
        break;
    }

    qDebug() << "Jump Successful";
}
