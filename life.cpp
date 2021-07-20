#include "life.h"
#include <iostream>
#include <unordered_map>
#include <list>
#include <random>
#include "windows.h"
using namespace std;

display::display(int x,int y,int width,int height,QGraphicsItem *parent):QGraphicsRectItem(x,y,width,height,parent)

{
    this->setBrush(QBrush(Qt::white));

}
display::~display()
{
    delete this;
}
void display::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    changeColor();
}

void display::changeColor()
{
    if(this->brush().color()==Qt::white)
    {
        this->setBrush(QBrush(Qt::green));
    }
    else
    {
        this->setBrush(QBrush(Qt::white));
    }
}

bool cell::operator==(const cell& p) const
{
    return x == p.x and y == p.y;
}

size_t MyHashFunction::operator()(const cell& var) const
        {
            return (hash<long long>()((long long)var.x * 0x10000 + var.y));
        }

Life::~Life()
{

    for (auto& item : planet)
    {
       delete item.second;
    }

}

void Life::add_cell(int x,int y,display* ptr)
{
    planet[{x, y}]=ptr;

}
display* Life::get_cell(cell xy)
{
     it = planet.find(xy);
    return (*it).second;

}

unordered_map<cell, display*, MyHashFunction>& Life::access_planet()
{
    return planet;
}

list<cell> Life::neighbors(const cell& var)
{
    list<cell> points;
    int x,y;

    for (int i = var.x - 1;i <=var.x + 1;++i)
    {
        for (int j = var.y - 1;j <=var.y + 1;++j)
        {
            if (!(var.x == i && var.y == j))
            {

                if (i == -1) x = width - 1;
                else if (i == width ) x = 0;
                else x = i;

                if (j == -1) y = height - 1;
                else if (j == height ) y = 0;
                else y = j;

                 points.push_back(cell(x, y));
            }
        }
    }
    //for (auto i : points) cout << i.x <<i.y<<" ";
    return points;
}


Life::Life(int h, int w)
{
    height = h;
    width = w;

}

