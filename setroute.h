#ifndef SETROUTE_H
#define SETROUTE_H

#include <QDialog>

namespace Ui {
class SetRoute;
}

class SetRoute : public QDialog
{
    Q_OBJECT

public:
    explicit SetRoute(QWidget *parent = 0);
    ~SetRoute();

private slots:
    void makemap();

    void on_MakeMap_clicked();

private:
    Ui::SetRoute *ui;
};

#endif // SETROUTE_H
