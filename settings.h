#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include "mainwindow.h"

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

    void on_PlayMusic_clicked();

    void on_OKCancel_rejected();

    void on_OKCancel_accepted();

    void on_ChangeMain_clicked();

signals:

    void ChangeMain_clicked(); //Needs to be a SIGNAL to be used in connect

private:
    Ui::Settings *ui;
};

#endif // SETTINGS_H
