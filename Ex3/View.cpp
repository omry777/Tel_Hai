#include "View.h"

View::View(float sc, int si)
{
    scale = sc;
    size = si;
    matrix = (char **)malloc(sizeof(char) * size * size);
    char *p = matrix[1];
    for (size_t i = 1; i < size; i++)
    {
        matrix[i] = p;
        p += size;
    }

    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            matrix[i][j] = ' ';
        }
        
    }
    

    origin = *(new Point());
    objects = *(new vector<Sim_object>(MAX_SIZE));
}

void View::draw()
{
    update_location();
    for (size_t i = 0; i < size + 2; i++)
    {
        cout << "---";
    }
    cout << endl;
    for (size_t i = 0; i < size; i++)
    {
        cout << "| ";
        for (size_t j = 0; j < size; j++)
        {
            cout << " " << matrix[i][j] << " ";
        }
        cout << " |" << endl;
    }

    for (size_t i = 0; i < size + 2; i++)
    {
        cout << "---";
    }
    cout << endl;
}

void View::update_location()
{
    int x, y;
    for (int i = 0; i < *objectCurr; i++)
    {
        if (inRange(objects[i].getLocation()))
        {
            x = objects[i].getLocation().getX() / scale;
            y = objects[i].getLocation().getY() / scale;
            matrix[x][y] = '*';
        }
    }
}

bool View::inRange(Point &p)
{
    Point endP = origin + Point(scale * size, scale * size);
    return (p > origin && p < endP);
}
