#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public:

    void setok();


private slots:


    void on_Quit_clicked();

    void on_NewGame_clicked();

    void on_Settings_clicked();

    void on_LoadGame_clicked();

    void on_ChangeLanguage_clicked();



public:
//should be private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
