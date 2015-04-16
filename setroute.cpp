#include "setroute.h"
#include "ui_setroute.h"
#include "QMessageBox"
#include "QVector"
#include "vector"

SetRoute::SetRoute(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetRoute)
{
    ui->setupUi(this);
}

SetRoute::~SetRoute()
{
    delete ui;
}


//Make a map to choose a location to travel to.


//*********Creating array of buttons*************//

void SetRoute::makemap(){

    //const int bttnsz = 31; //Size of a button that can display one char.

//QWidget *wdg = new QWidget(this);


//QVector<int> ces [100];

//for (int i = 0;i<ces.size();i++){
//    ces[i].push_back(i);
//ui->progressBar->setValue(ces[i]);}
//
//ui->MapFrame->setLayout(wdg);


}
//************************************************//
void SetRoute::on_MakeMap_clicked()
{
    makemap();
}
