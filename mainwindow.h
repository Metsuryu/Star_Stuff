#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "settings.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:


    void on_Quit_clicked();

    void on_NewGame_clicked();

    void on_Settings_clicked();

    void on_LoadGame_clicked();

    void on_ChangeLanguage_clicked();

    void setok();


private:
    Ui::MainWindow *ui;

};


#endif // MAINWINDOW_H
