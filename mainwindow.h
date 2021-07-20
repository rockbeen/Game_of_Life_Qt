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

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_timer_timeout();
public:
    MainWindow(int x,int y);

    ~MainWindow();

private:
    Ui::MainWindow *ui;
    int x,y;
    int height, width, iterations;
    QTimer *timer;
    //Life a(height, width);
    QGraphicsScene * scene;
    void new_game();
    QVector<QVector<display*> > fills;
    Life *game_of_life;


};
#endif // MAINWINDOW_H
