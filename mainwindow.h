#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QtWidgets>
#include <QDebug>
#include "life.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private slots:

    void on_pushButton_clicked();//"new game" button
    void on_pushButton_2_clicked();//start of the game
    void new_iterations();
    void on_pushButton_3_clicked();//live cells are set randomly

public:
    MainWindow(int x,int y);

    ~MainWindow();

private:
    Ui::MainWindow *ui;
    int x,y;
    int  iterations;
    QTimer *timer;
    //Life a(height, width);
    QGraphicsScene* scene;
    Life *game_of_life;//the class of the game itself
    void new_game();


};
#endif // MAINWINDOW_H
