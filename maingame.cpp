#include "maingame.h"
#include "ui_maingame.h"
#include "settings.h"
#include "setroute.h"

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

//bool unsaved(); //TODO: Implement this to check if there is unsaved data and use it on closeEvent();

void MainGame::closeEvent(QCloseEvent *event)
{
    event->ignore();
    QApplication::quit(); //Quit without asking for now. TODO: Ask before quitting.
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

