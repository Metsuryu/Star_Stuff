#ifndef SETROUTE_H
#define SETROUTE_H

#include <QDialog>
#include "location_pushbutton.h"
#include "settings.h"
#include "QMessageBox"

const int matrixsize =10; //Size of the matrix
const int bttnsz = 31; //Size of a button that can display one char.
const unsigned int ener_cost = 10;
extern void not_enough_energy_message();
extern void already_here_message();
extern double energy_required_value;

namespace Ui {
class SetRoute;
}

class SetRoute : public QDialog
{
    Q_OBJECT

public:
    explicit SetRoute(QWidget *parent = 0);
    ~SetRoute();
    double energy_required=0.0; //% Of energy required
    double energy_available=0.0;//% Of energy available

private slots:

    void makemap();
    void mapinfo();

    void on_BTJumpToLocation_clicked();

    void on_BTCancel_clicked();

private:
    Ui::SetRoute *ui;

   //QPushButton *mapbutton[matrixsize][matrixsize]; //Forward declaration of matrix of buttons
    location_PushButton *lpb[matrixsize][matrixsize]; //This has "loc" as a public member.
};

#endif // SETROUTE_H
