#include "View.h"

View::View() : _size(25), scale(2){};

void View::draw()
{
    int temp, maxDigitsX = 1, maxDigitsY = 1, cnt;
    temp = origin.getX() + scale * _size;
    while ((temp /= 10))
        maxDigitsX++;
    temp = origin.getY() + scale * _size;
    while ((temp /= 10))
        maxDigitsY++;
    update();
    for (int i = 0; i < maxDigitsY-1; i++)
        cout << " ";
    for (size_t i = 0; i < _size + 2; i++)
    {
        cout << "---";
    }
    cout << endl;
    for (int i = _size - 1; i >= 0; i--)
    {
        cnt = 1;
        if (i % 3 == 0)
        {
            cout << (temp = origin.getY() + i * scale);
            while (temp /= 10)
                cnt++;
            if (cnt < maxDigitsY)
                cout << " ";
        }
        else
        {
            for (int i = 0; i < maxDigitsY; i++)
                cout << " ";
        }

        cout << "| ";
        for (size_t j = 0; j < _size; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << " |" << endl;
    }

    for (int i = 0; i < maxDigitsY-1; i++)
        cout << " ";
    for (size_t i = 0; i < _size + 2; i++)
    {
        cout << "---";
    }
    cout << endl;

    for (int i = -2; i < maxDigitsY; i++)
        cout << " ";
    for (size_t i = 0; i < _size; i += 3)
    {
        cnt = 1;
        cout << (temp = origin.getX() + i * scale) << "       ";
        while (temp /= 10)
            cnt++;
        if (cnt < maxDigitsX)
            cout << " ";
    }
    cout << endl;
    for (const auto &obj : *objects)
        obj->print();
    cout << "----------" << endl
         << endl;
}

void View::update()
{
    for (size_t i = 0; i < _size; i++)
        for (size_t j = 0; j < _size; j++)
            matrix[i][j] = ". ";

    int x, y;
    Point temp;
    for (auto &o : *objects)
    {
        if (inRange(*o))
        {
            temp = o->loc - origin;
            x = temp.getX() / scale;
            y = temp.getY() / scale;
            matrix[y][x] = o->name.substr(0, 2);
            if (matrix[y][x].length() < 2)
                matrix[y][x] += " ";
        }
    }
}

bool View::inRange(const Sim_object &p)
{
    return (p.loc >= origin && p.loc < origin + ((float)(scale * _size)));
}

View::~View()
{
}
