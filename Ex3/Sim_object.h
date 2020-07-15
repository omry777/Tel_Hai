#ifndef SIM_OBJECT_H
#define SIM_OBJECT_H

#include "Point.h"
#include <string>

using namespace std;

class Sim_object
{
private:
    Point loc;
    string name;

    friend class View;
    friend class Model;
    friend ostream &operator<<(ostream &out, const Sim_object &obj);
public:
    Sim_object(string nm = "NO NAME", float x = 0, float y = 0);
    ~Sim_object() {}

    //TODO: Add update()
};
ostream &operator<<(ostream &out, const Sim_object &obj);

#endif