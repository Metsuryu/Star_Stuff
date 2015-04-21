#ifndef SETROUTE_H
#define SETROUTE_H

#include <QDialog>
const int matrixsize =10; //Size of the matrix
const int bttnsz = 31; //Size of a button that can display one char.

namespace Ui {
class SetRoute;
}

class SetRoute : public QDialog
{
    Q_OBJECT

public:
    explicit SetRoute(QWidget *parent = 0);
    ~SetRoute();
    int energy_required=0; //% Of energy required
    int energy_available=0;//% Of energy available
private slots:

    void makemap();
    void mapinfo ();



private:
    Ui::SetRoute *ui;

    QPushButton *mapbutton[matrixsize][matrixsize]; //Forward declaration of matrix of buttons
};

#endif // SETROUTE_H
