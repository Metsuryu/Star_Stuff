#ifndef MAINGAME_H
#define MAINGAME_H

#include <QMainWindow>
#include <QString>


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

    void on_BTSetRoute_clicked();

    void jump();

    void on_BTEnter_clicked();

private:
    Ui::MainGame *ui;

//protected:
    void closeEvent(QCloseEvent *event);
};

#endif // MAINGAME_H
