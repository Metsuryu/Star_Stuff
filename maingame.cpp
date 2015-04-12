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



void MainGame::on_actionQuit_triggered()
{
        QApplication::quit();
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
