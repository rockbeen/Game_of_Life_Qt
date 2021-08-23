#ifndef LIFE_H
#define LIFE_H
#include <QMainWindow>
#include <QtWidgets>
#include <QObject>
#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;
class display : public QGraphicsRectItem
{
public:
    display(qreal x,qreal y,qreal width,qreal height,QGraphicsItem *parent =0);
    ~display();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void changeColor();
};

struct cell//one cell
{
    int x;
    int y;
    cell(int X, int Y)
    {
        x = X;
        y = Y;
    }
    bool operator==(const cell& p) const;

};
class MyHashFunction {//Hash function for a hash table
    public:

        size_t operator()(const cell& var) const;
};

class Life//the class of the game itself
{
    private:
        int height, width;
        unordered_map<cell,display*, MyHashFunction> planet;//all cells with their value (live/dead) are stored in a hash table
        unordered_map<cell,display*, MyHashFunction>::iterator it;

    public:
        Life(int, int);
        ~Life();
        unordered_map<cell, display*, MyHashFunction>& access_planet();//get a table
        void add_cell(int x,int y,display* ptr);//add a cell
        display* get_cell(cell);//return the cell value
        list<cell>neighbors(const cell& var);//list of cell neighbors
};

#endif // LIFE_H
