#ifndef VIEW_H
#define VIEW_H

#include "Model.h"
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
    float scale;
    string matrix[30][30];
    Point origin;
    list<Sim_object *> *objects;
    int _size;
    bool inRange(const Sim_object &);

public:
    View();
    void draw();
    void update();
    int getSize() { return _size; };
    void setSize(int s) { _size = s; };
    float getScale() { return scale; };
    void setScale(float s) { scale = s; };
    void setOrigin(Point &p) { origin = p; };
    Point &getOrigin() { return origin; };
    void toDefault();
    void size(int newSize);
    void zoom(float _scale);

    void pan(float x, float y);

    void show() const;
    void setObjects(list<Sim_object *> &objcts) { objects = &objcts; }

    ~View();
};

#endif