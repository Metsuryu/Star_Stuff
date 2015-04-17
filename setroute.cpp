#include "setroute.h"
#include "ui_setroute.h"

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


//********************Creating Map********************//

void SetRoute::makemap(){

    //********************Creating matrix of buttons******************************//
    const int matrixsize =4; //Size of the matrix
    const int bttnsz = 31; //Size of a button that can display one char.
    QPushButton* mapbutton[matrixsize][matrixsize];
    //  QGridLayout *grly = new QGridLayout;

    for (int i=0; i<=matrixsize-1; i++)//Fill map
    {{for (int j=0;j<=matrixsize-1;j++)
            {mapbutton[i][j] = new QPushButton("x",ui->MapFrame);
                mapbutton[i][j]->setMaximumSize(bttnsz,bttnsz);
                // grly->addWidget(mapbutton[i][j]);
                mapbutton[i][j]->move(40*i,40*j); //This does not add the buttons to the layout, but it is a grid.
                //ui->MapFrame->layout()->addWidget(mapbutton[i][j]); //MapLayout is the name of the layout of MapFrame this is equivalent to the following line
                //ui->MapLayout->addWidget(mapbutton[i][j]); //This adds the buttons to the layout, but in a vertical line, not a grid.
                mapbutton[i][j]->show();
            }
        }}
}



void SetRoute::on_MakeMap_clicked()
{
    makemap();    
}
