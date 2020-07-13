#ifndef VIEW_H
#define VIEW_H
#include "Sim_object.h"
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

class View
{
private:
    float scale;
    int size;
    char **matrix;
    //Point origin;
    Sim_object **objects;
    size_t *objectCurr;

    //bool inRange(Point &p);

public:
    View(float sc = 2, int si = 25);
    void draw();
    void update_location();
    int getSize() { return size; };
    void setSize(int s) { size = s; };
    float getScale() { return scale; };
    void setScale(float s) { scale = s; };
    //void setOrigin(Point &p) { origin = p; };
    //Point &getOrigin() { return origin; };
    void setObjects(Sim_object **objcts, size_t *curr)
    {
        objects = objcts;
        objectCurr = curr;
    }
    bool inRange(Sim_object&);

    ~View(){};
};

#endif