#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(int x, int y) :x(x),y(y),iterations(0),scene(NULL),
    QMainWindow(0)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer= new QTimer();
    timer->setInterval(500);
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(on_timer_timeout()));
    game_of_life= new Life(x,y);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    new_game();
}
void MainWindow::on_timer_timeout()
{
    list<cell> neig;
    unsigned int alive_neighbors = 0;
    bool result=0;
    list<cell> alive;

    for (auto& item : game_of_life->access_planet())
    {

        neig = game_of_life->neighbors(item.first);
        for (const auto& i : neig)
        {

            if  (game_of_life->get_cell(i)->brush().color() == Qt::green)
            {
                ++alive_neighbors;

            }
        }

        if (item.second->brush().color() == Qt::white && alive_neighbors ==3 ) alive.push_back(item.first);
        else if(item.second->brush().color() == Qt::green && (alive_neighbors < 2 || alive_neighbors > 3)) alive.push_back(item.first);

        if (item.second->brush().color() == Qt::green && (alive_neighbors== 2 || alive_neighbors == 3))result=1;

        alive_neighbors = 0;
    }
    if (alive.empty()&& result==1)
    {
        timer->stop();
        QMessageBox::about(this, "Won","You won!\nIterations: "+QString().setNum(iterations));
    }
    else if (alive.empty()&& result==0)
    {
        timer->stop();
        QMessageBox::about(this, "Loss","Game Over!\nIterations: "+QString().setNum(iterations));
    }

    else
    {
        for (auto& item : alive)
        {
            game_of_life->get_cell(item)->changeColor();

        }
        ++iterations;
        result=0;
    }

}
void MainWindow::on_pushButton_2_clicked()
{
    if(scene != NULL)
        timer->start();
}

void MainWindow::new_game()
{
    if (scene==NULL)
   {
    scene= new QGraphicsScene(0,0,ui->graphicsView->viewport()->width(),ui->graphicsView->viewport()->height());
    for(int i =0;i<x;++i)
    {
        for(int j=0;j<y;j++)
        {
            display* rec= new display(0,0,scene->sceneRect().width()/(x),scene->sceneRect().height()/(y));
            scene->addItem(rec);
            rec->setPos(0+i*scene->width()/(x),0+j*scene->height()/(y));
            game_of_life->add_cell(i,j,rec);
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
