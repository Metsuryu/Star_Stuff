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

private:
    Ui::SetRoute *ui;
};

#endif // SETROUTE_H
