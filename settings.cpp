#include "settings.h"
#include "ui_settings.h"
#include <QMediaPlayer>
#include "mainwindow.h"
#include "funcs.h"



Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);

}

Settings::~Settings()
{
    delete ui;
}



//TODO: add settings

void Settings::on_OKCancel_accepted()
{

    //TODO: Save settings
}
void Settings::on_OKCancel_rejected()
{

}

//Plays music
bool musicplaying = false;
QMediaPlayer *music = new QMediaPlayer;

void Settings::on_PlayMusic_clicked()
{
    music->setMedia(QUrl("qrc:/music/Vedrim_Desperado.mp3"));;
    music->setVolume(50);


    if (musicplaying){

        music->stop();
        ui->PlayMusic->setText("Play Music");
        musicplaying = false;

    }else{

        music->play();
        ui->PlayMusic->setText("Stop Music");
        musicplaying = true;
    }
}



void Settings::on_ChangeMain_clicked()
{
    emit ChangeMain_clicked();
}

void ChangeMain_clicked(){}
