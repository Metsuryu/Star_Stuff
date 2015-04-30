#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include "mainwindow.h"
#include "QMediaPlayer"
#include "QString"
#include "initializer_list"

//**Settings variables**//

extern bool quit_confirm;
extern bool musicplaying;
extern QMediaPlayer *music;
extern int volume;
extern double sfx_volume;
extern bool sfx_enabled;
extern bool eng;
extern bool ita;
extern void save_settings();
extern void load_settings();
extern int current_sector;

extern int hull;
extern int gold;
//QString location;
//vector<string> inventory;
extern int inventory_capacity;
extern double energy;
extern double energy_capacity;
extern int drones_active_total;
extern int inventory_load;
extern int distance;
extern QString redbar;
extern QString greenbar;
extern int selected_location;
extern void error_generic();
extern bool nemesis;


enum class location_event
{
    ASTEROID = 0,
    ENEMY_SHIP = 1,
    FRIENDLY_SHIP = 2,
    COMMERCE_SHIP = 3,
    PLANET = 4,
    STAR = 5,
    SPACE_STATION = 6,
    //Specials
    BOSS1 = 7,
    BOSS2 = 8,
    BOSS3 = 9,
    BOSS4 = 10,
    FINAL_BOSS = 11,
    NO_JUMP = 12,
    QUEST = 13
    //TODO: Maybe add other QUEST enums, or use just this one with a counter.
};

extern location_event loc_event;

//**********************//

namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = 0);
    ~Settings();

private slots:

    void on_OKCancel_rejected();

    void on_OKCancel_accepted();

    void on_ChangeMain_clicked();

    void on_CheckBox_QuitConfirmation_toggled(bool checked);

    void on_CheckBox_Music_released();

    void on_Slider_Music_valueChanged(int value);

    void on_EngRadioButton_toggled(bool checked);

    void on_ItaRadioButton_toggled(bool checked);

    void on_checkBox_sfx_toggled(bool checked);

signals:

    void ChangeMain_clicked(); //Needs to be a SIGNAL to be used in connect

private:
    Ui::Settings *ui;
};

#endif // SETTINGS_H
