#include "settings.h"
#include "ui_settings.h"
#include "mainwindow.h"
#include <QFile>
#include "QString"
#include "QMessageBox"

Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    ui->CheckBox_QuitConfirmation->setChecked(quit_confirm);
    ui->checkBox_sfx->setChecked(sfx_enabled);
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
bool quit_confirm = false;//Confirm before quitting setting.
bool musicplaying = false;
int volume = 42;
double sfx_volume = 0.41;
bool sfx_enabled = false;
bool eng = true;
bool ita = false;

int hull = 89;
int gold = 10;
QString location = "Space Station 1";//TODO: Temp. name, to change
int current_sector = 1;
//vector<string> inventory;
int inventory_capacity = 100;
double energy = 42.0;
double energy_capacity = 100.0;
int drones_active_total = 0;
int inventory_load = 0;
int distance = 0;//Distance in tiles from current location
QString redbar = "QProgressBar{text-align:center;} QProgressBar::chunk{background-color: qlineargradient(spread:reflect, x1:0, y1:1, x2:0, y2:0.119, stop:0.289773 rgba(255, 0, 0, 255), stop:1 rgba(255, 171, 171, 255));}";
QString greenbar = "QProgressBar{text-align:center;}";
int selected_location = 0;
location_event loc_event = location_event::NO_JUMP;
bool nemesis = false; //Is set to true if you are enemy with both factions

QString testst = QString("%1").arg(energy);







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

//***************Music***************// //TODO: Make a playlist and loop it.
void Settings::on_CheckBox_Music_clicked()
{
    if (musicplaying)
    {
        music->stop();
        musicplaying = false;
    }else{
        music->setMedia(QUrl("qrc:/music/sfx/Vedrim_Desperado.mp3"));
        music->setVolume(ui->Slider_Music->value());
        music->play();
        musicplaying = true;
    }
}
//**//
void Settings::on_Slider_Music_valueChanged(int value)
{
    volume=value;
    music->setVolume(volume);

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

void error_generic()//TODO: Use only until there are better errors available.
{    
    QMessageBox eg;
    eg.setText("Something went wrong.");
    eg.setInformativeText("An unexpected error has occurred.");
    eg.setWindowTitle("Error.");
    eg.setStandardButtons(QMessageBox::Ok);
    eg.setDefaultButton(QMessageBox::Ok);
    eg.setIcon(QMessageBox::Warning);
    eg.exec();
}


void Settings::on_checkBox_sfx_toggled(bool checked)
{
    sfx_enabled=checked;
}

