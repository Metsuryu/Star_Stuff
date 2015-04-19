#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include "mainwindow.h"
#include "QMediaPlayer"

//**Settings variables**//

extern bool quit_confirm;
extern bool musicplaying;
extern QMediaPlayer *music;
extern int volume;
extern bool eng;
extern bool ita;

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

signals:

    void ChangeMain_clicked(); //Needs to be a SIGNAL to be used in connect

private:
    Ui::Settings *ui;
};

#endif // SETTINGS_H
