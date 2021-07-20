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

struct cell
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
class MyHashFunction {
    public:

        size_t operator()(const cell& var) const;
};

class Life
{
    private:
        int height, width;
        unordered_map<cell,display*, MyHashFunction> planet;
        unordered_map<cell,display*, MyHashFunction>::iterator it;

    public:
        Life(int, int);
        ~Life();
        unordered_map<cell, display*, MyHashFunction>& access_planet();
        void add_cell(int x,int y,display* ptr);
        display* get_cell(cell);
        list<cell>neighbors(const cell& var);
};

#endif // LIFE_H
