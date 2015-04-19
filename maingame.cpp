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
}

MainGame::~MainGame()
{
    delete ui;
}

//TODO: option to confirm quit

void MainGame::closeEvent(QCloseEvent *event) //Asks the user for confirmation to quit.
{   
    event->ignore();
    if(quit_confirm)
    {
    QMessageBox unsaved_alert;//TODO: Have option to disable quit warning.
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
          // Do nothing.
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

void MainGame::on_SetRoute_clicked()
{
    SetRoute setroute;
    setroute.setModal(true);
    setroute.exec();
}

