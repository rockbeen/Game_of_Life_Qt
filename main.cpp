#include "mainwindow.h"
#include <QInputDialog>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    bool Ok;
    int x =QInputDialog::getInt( 0, "Game of Life", "Enter the size:", 10,5,100,0,&Ok);

    if (Ok) {

        }
        MainWindow w(x,x);
        w.show();

    return a.exec();
}
