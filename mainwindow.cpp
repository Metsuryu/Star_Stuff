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

void MainWindow::on_Quit_clicked()
{
    QApplication::quit();
}

void MainWindow::on_NewGame_clicked()
{
    MainGame *mgame = new MainGame;
    mgame->show();
    this->hide();
}

void MainWindow::on_Settings_clicked()
{
    Settings sttngs;
    sttngs.setModal(true);
    sttngs.exec();
}

//test comment
