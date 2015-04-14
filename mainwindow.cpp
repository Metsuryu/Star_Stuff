#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "maingame.h"
#include "settings.h"





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
    this->destroy();
}

void MainWindow::on_Settings_clicked() //Opens settings
{
    //Settings* settings = new Settings;
    Settings settings;
    connect(&settings,SIGNAL(ChangeMain_clicked()),this,SLOT(setok())); //this gives me the error
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


void MainWindow::setok()
{
   // MainWindow *mn = new MainWindow(); //Doesn't work
   // mn->ui->TitleLabel->setText("OK.");
    ui->TitleLabel->setText("OK.");
    ui->NewGame->setText("OK.");
}

































