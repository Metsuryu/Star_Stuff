#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "maingame.h"
#include "settings.h"
#include "iostream"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_Quit_clicked() //Quits game
{
    QApplication::quit();
}

void MainWindow::on_NewGame_clicked()  //Opens Maingame window
{
    MainGame *mgame = new MainGame;
    mgame->setWindowTitle("Star Stuff");
    mgame->show();
    this->hide();
}

void MainWindow::on_Settings_clicked() //Opens settings
{
    Settings settings;
    settings.setModal(true);
    settings.exec();
}

void MainWindow::on_LoadGame_clicked()
{
    //TODO: Load Game from an encoded save-file.

}


void MainWindow::on_ChangeLanguage_clicked()
{
    //TODO: Make a "Change language" function that translates the game in the other language.
    //Also, add potential to add another language.

    //Placeholder code:
        ui->NewGame->setText("Gioca");
}

void setok()
{
   // using namespace std;
   // cout << "OK Clicked\n";

    MainWindow *mn= new MainWindow;
    mn->ui->TitleLabel->setText("OK.");
    mn->ui->NewGame->setText("OK");
   //MainWindow::ui->TitleLabel->setText("OK"); //Try to make this work
}


