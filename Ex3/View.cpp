#include "View.h"

View::View(float sc, int si)
{
    scale = sc;
    size = si;
    matrix = new char *[size];
    for (size_t i = 0; i < size; i++)
    {
        matrix[i] = new char[size];
        for (size_t j = 0; j < size; j++)
        {
            matrix[i][j] = ' ';
        }
    }
    origin = Point();
}

void View::draw()
{   
    update();
    for (size_t i = 0; i < size + 3; i++)
    {
        cout << "--";
    }
    cout << endl;
    for (int i = size - 1; i >= 0; i--)
    {
        cout << " | ";
        for (size_t j = 0; j < size; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << " |" << endl;
    }

    for (size_t i = 0; i < size + 3; i++)
    {
        cout << "--";
    }
    cout << endl;
    for (const auto &obj : *objects)
        cout << *obj << endl;
    cout << "----------" << endl<< endl;
}

void View::update()
{
    for (size_t i = 0; i < size; i++)
        for (size_t j = 0; j < size; j++)
            matrix[i][j] = ' ';

    int x, y;
    for (auto &o : *objects)
    {
        if (inRange(*o))
        {
            x = o->loc.getX() / scale;
            y = o->loc.getY() / scale;
            matrix[x][y] = '*';
        }
    }
}

bool View::inRange(const Sim_object &p)
{
    return (p.loc >= origin && p.loc < (float)(scale * size));
}

View::~View()
{
    for (size_t i = 0; i < size; i++)
        delete[] matrix[i];

    delete[] matrix;
}
