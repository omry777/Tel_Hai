#include "View.h"


View::View(): _size(25), scale(2){};

void View::draw()
{   
    update();
    for (size_t i = 0; i < _size + 3; i++)
    {
        cout << "--";
    }
    cout << endl;
    for (int i = _size - 1; i >= 0; i--)
    {
        cout << " | ";
        for (size_t j = 0; j < _size; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << " |" << endl;
    }

    for (size_t i = 0; i < _size + 3; i++)
    {
        cout << "--";
    }
    cout << endl;
    for (const auto &obj : *objects)
        obj->print();
    cout << "----------" << endl<< endl;
}

void View::update()
{
    for (size_t i = 0; i < _size; i++)
        for (size_t j = 0; j < _size; j++)
            matrix[i][j] = ' ';

    int x, y;
    for (auto &o : *objects)
    {
        if (inRange(*o))
        {
            x = o->loc.getX() / scale;
            y = o->loc.getY() / scale;
            matrix[x][y] = o->getSign();
        }
    }
}

bool View::inRange(const Sim_object &p)
{
    return (p.loc >= origin && p.loc < (float)(scale * _size));
}

View::~View()
{
}
