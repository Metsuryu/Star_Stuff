#include "settings.h"
#include "ui_settings.h"
#include "mainwindow.h"
#include <QFile>
#include "QString"

Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    ui->CheckBox_QuitConfirmation->setChecked(quit_confirm);
    ui->CheckBox_Music->setChecked(musicplaying);
    ui->Slider_Music->setValue(volume);
    ui->ItaRadioButton->setChecked(ita);
    if(ita)//TODO: This is a placeholder. Instead of this, call a function that translates everything
    {
        ui->SettingsLabel->setText("Impostazioni");
        ui->CheckBox_QuitConfirmation->setText("Chiedi conferma prima di chiudere");
        ui->CheckBox_Music->setText("Musica");
        ui->OKCancel->button(QDialogButtonBox::Cancel)->setText(tr("Annulla"));        
    }
}

Settings::~Settings()
{
    delete ui;
}

//**Settings variables**// //TODO: If there is a savefile, read settings from it at startup.
QMediaPlayer *music = new QMediaPlayer;
bool quit_confirm=false;
bool musicplaying = false;
int volume=42;
bool eng=true;
bool ita=false;
//int energy
//int hull
//int gold
//string location
int current_sector = 1;
//Vector<string> inventory
//int inventory capacity
//int fuel capacity
//int total active drones
enum location_event
{
    ASTEROID = 0,
    ENEMY_SHIP = 1,
    FRIENDLY_SHIP = 2,
    COMMERCE_SHIP = 3,
    PLANET = 4,
    STAR = 5,
    SPACE_STATION = 6
};


//**Save settings**// //TODO: Change filename to settings.config or something similar
void save_settings()
{
    QFile save_file("settings.txt");
    if (!save_file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&save_file);//TODO: Add other settings
    out << volume << "\n";
    save_file.close();
}
//**Settings Saved**//

//**Load Settings**//
void load_settings()
{
    QFile load_file("settings.txt");//TODO: Match name of savefile
    if (!load_file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&load_file);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        volume=line.toInt();//TODO: Complete this function
    }
}

//**Settings Loaded**//

//**********************//


void Settings::on_OKCancel_accepted()
{
    save_settings();
    //TODO: Save settings
}
void Settings::on_OKCancel_rejected()
{
    //TODO: Discard changes, maybe by setting them to default,
    //or loading previous value from save
}

//**TODO: Remove test function**//
void Settings::on_ChangeMain_clicked()
{
    emit ChangeMain_clicked();
}
void ChangeMain_clicked(){}
//**//

//**Cofirm quit**//
void Settings::on_CheckBox_QuitConfirmation_toggled(bool checked)
{
    quit_confirm=checked;
}
//*************//

//***************Music***************//
void Settings::on_CheckBox_Music_released()
{
    if (musicplaying)
    {
        music->stop();
        musicplaying = false;
    }else{
        music->setMedia(QUrl("qrc:/music/Vedrim_Desperado.mp3"));;
        music->setVolume(ui->Slider_Music->value());
        music->play();
        musicplaying = true;
    }
}
//**//
void Settings::on_Slider_Music_valueChanged(int value)
{
    volume=value;
    music->setVolume(value);

}
//*****************************************//

//**Language**//
void Settings::on_EngRadioButton_toggled(bool checked)
{
    eng=checked;
    ita=(!checked);
}
//**//
void Settings::on_ItaRadioButton_toggled(bool checked)
{
    ita=checked;
    eng=(!checked);
}
//***************//
