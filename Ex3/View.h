#ifndef VIEW_H
#define VIEW_H
#include "Sim_object.h"
#include "Point.h"
#include <iostream>
#include <string>
#include <list>

using namespace std;

class View
{
    // TODO: incorporate images and better view screen
private:
    float scale = 2;
    int size = 25;
    char matrix[30][30];
    Point origin;
    list<Sim_object *> *objects;

    bool inRange(const Sim_object &);

public:
    View(float sc = 2, int si = 25);
    void draw();
    void update();
    int getSize() { return size; };
    void setSize(int s) { size = s; };
    float getScale() { return scale; };
    void setScale(float s) { scale = s; };
    void setOrigin(Point &p) { origin = p; };
    Point &getOrigin() { return origin; };
    void setObjects(list<Sim_object *> &objcts) { objects = &objcts; }

    ~View();
};

#endif