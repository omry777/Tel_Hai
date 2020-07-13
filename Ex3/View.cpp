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


    //origin = Point();      TODO: WTF IS WRONG HERE?! 
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
        cout << " | ";
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

         if ( inRange(*objects[i]))
         {
             cerr << i << endl;
             x = objects[i]->x/ scale;
             y = objects[i]->y / scale;
             matrix[x][y] = '*';
         }
    }
}

 bool View::inRange(Sim_object &p)
 {
     return (p.x > 0 && p.y > 0 && p.x < scale * size && p.y < scale * size );
 }
