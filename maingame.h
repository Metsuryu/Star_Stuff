#ifndef MAINGAME_H
#define MAINGAME_H

#include <QMainWindow>

namespace Ui {
class MainGame;
}

class MainGame : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainGame(QWidget *parent = 0);
    ~MainGame();

private slots:
    void on_actionQuit_triggered();

    void on_actionSettings_triggered();

    void on_SetRoute_clicked();

private:
    Ui::MainGame *ui;
};

#endif // MAINGAME_H
