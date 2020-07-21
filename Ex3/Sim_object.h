#ifndef SIM_OBJECT_H
#define SIM_OBJECT_H

#include "Point.h"
#include <string>

using namespace std;

class Sim_object
{
protected:
    Point loc;
    string name;

    friend class View;
    friend class Model;
    friend ostream &operator<<(ostream &out, const Sim_object &obj);
public:
    Sim_object(string nm = "NO NAME", Point p = Point());
    ~Sim_object() {}


    //TODO: Add update()
};
ostream &operator<<(ostream &out, const Sim_object &obj);

#endif