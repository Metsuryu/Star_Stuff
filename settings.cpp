#include "settings.h"
#include "ui_settings.h"
#include <QMediaPlayer>
#include "mainwindow.h"
#include "mainwindow.cpp"



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
    setok();
}
void Settings::on_OKCancel_rejected()
{
//    MainWindow::ui->TitleLabel->setText("Cancel");
        setok();
}

//TODO: Clean this code for music:
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





