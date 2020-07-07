#ifndef VIEW_H
#define VIEW_H
#include "Sim_object.h"

using namespace std;

class View
{
private:
    float scale;
    int size;
    char **matrix;
    Point origin;
    vector<Sim_object> objects;
    int *objectCurr;

    bool inRange(Point &p);
public:
    View(float sc = 2, int si = 25);
    void draw();
    void update_location();
    int getSize(){return size;};
    void setSize(int s){size = s;};
    float getScale(){return scale;};
    void setScale(float s){scale = s;};
    void setOrigin(Point p ){origin=p;};
    Point& getOrigin(){return origin;};
    void setObjects(vector<Sim_object> &objcts, int *curr){objects = objcts; objectCurr = curr;}

    ~View(){};
};


#endif