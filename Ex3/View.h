#ifndef VIEW_H
#define VIEW_H
#include "Sim_object.h"
#include "Point.h"
#include <iostream>
#include <string>
#include <list>

using namespace std;

typedef list<Sim_object> ListType;
class View
{
    // TODO: incorporate images and better view screen
private:
    float scale = 2;
    int size = 25;
    char **matrix;
    Point origin;
    ListType *objects;

    bool inRange(const Sim_object &);

public:
    View(float sc = 2, int si = 25);
    void draw();
    void update_location();
    int getSize() { return size; };
    void setSize(int s) { size = s; };
    float getScale() { return scale; };
    void setScale(float s) { scale = s; };
    void setOrigin(Point &p) { origin = p; };
    Point &getOrigin() { return origin; };
    void setObjects(ListType &objcts) { objects = &objcts; }

    ~View();
};

#endif