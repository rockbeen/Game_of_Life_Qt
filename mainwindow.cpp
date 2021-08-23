#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdlib.h>
#include <time.h>

MainWindow::MainWindow(int x, int y) :x(x),y(y),iterations(0),scene(NULL), QMainWindow(0), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer= new QTimer();
    timer->setInterval(250);
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(new_iterations()));
    game_of_life= new Life(x,y);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()//"new game" button
{
    new_game();
}
void MainWindow::new_iterations()
{
    if (iterations<1000)
    {
    list<cell> neig;
    unsigned int alive_neighbors = 0;
    bool result=0;
    list<cell> alive;

    for (auto& item : game_of_life->access_planet())//we go around each cell and look for neighbors for it
    {

        neig = game_of_life->neighbors(item.first);
        for (const auto& i : neig)
        {

            if  (game_of_life->get_cell(i)->brush().color() == Qt::green)//if the cell is alive, we add it to the list
            {
                ++alive_neighbors;

            }
        }

        if (item.second->brush().color() == Qt::white && alive_neighbors ==3 ) alive.push_back(item.first);//adding live cells to the list
        else if(item.second->brush().color() == Qt::green && (alive_neighbors < 2 || alive_neighbors > 3)) alive.push_back(item.first);

        if (item.second->brush().color() == Qt::green && (alive_neighbors== 2 || alive_neighbors == 3))result=1;

        alive_neighbors = 0;
    }
    if (alive.empty()&& result==1)//stable system
    {
        timer->stop();
        QMessageBox::about(this, "Won","You won!\nIterations: "+QString().setNum(iterations));
        iterations=0;
    }
    else if (alive.empty()&& result==0)//all life is dead
    {
        timer->stop();
        QMessageBox::about(this, "Loss","Game Over!\nIterations: "+QString().setNum(iterations));
        iterations=0;
    }

    else
    {
        for (auto& item : alive)//system updates
        {
            game_of_life->get_cell(item)->changeColor();

        }
        ++iterations;
        result=0;
    }
    }
    else
    {
        timer->stop();
        QMessageBox::about(this, "Max","The maximum number of iterations has been reached!\nIterations: "+QString().setNum(iterations));
        iterations=0;
    }

}
void MainWindow::on_pushButton_2_clicked()//start of the game
{
    if(scene != NULL)
        timer->start();
}

void MainWindow::new_game()//new game(creating / updating a scene)
{


    if (scene==NULL)
   {
    scene= new QGraphicsScene(0,0,ui->graphicsView->viewport()->width(),ui->graphicsView->viewport()->height());
    for(int i =0;i<x;++i)
    {
        for(int j=0;j<y;j++)
        {
            display* ptr= new display(0,0,scene->sceneRect().width()/(x),scene->sceneRect().height()/(y));
            scene->addItem(ptr);
            ptr->setPos(i*scene->width()/(x),j*scene->height()/(y));
            game_of_life->add_cell(i,j,ptr);
        }

    }
    }
    else
    {
        timer->stop();
        iterations=0;
        for(int i =0;i<x;++i)
        {
            for(int j=0;j<y;j++)
            {
                game_of_life->get_cell({i,j})->setBrush(QBrush(Qt::white));

            }
        }

      }
     ui->graphicsView->setScene(scene);
}

void MainWindow::on_pushButton_3_clicked()//live cells are set randomly
{
    srand(time(NULL));

    if(scene != NULL)
    {

    for (int i = 0;i < x;++i)
        for (int j = 0;j < y;++j)
        {
             unsigned int num = rand();
            if (num % 2 == 0)
                game_of_life->get_cell({i,j})->setBrush(QBrush(Qt::green));

            else
                game_of_life->get_cell({i,j})->setBrush(QBrush(Qt::white));
        }

    }
}


