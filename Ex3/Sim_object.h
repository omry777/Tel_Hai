#ifndef SIM_OBJECT_H
#define SIM_OBJECT_H
#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstring>
#include "Point.h"
#include <vector>
#define MAX_SIZE 100

class Sim_object
{
protected:
    Point location;
    string name;
public:
    Sim_object();
    Sim_object(string name, Point loc);

    string &getName(){return name;};
    Point &getLocation(){return location;}
    void update();
    //brodcast_current_state();
    ~Sim_object();
};




#endif