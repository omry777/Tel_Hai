#ifndef STRUCTURES_H
#define STRUCTURES_H

#include "Sim_object.h"

class Structure : public Sim_object
{
protected:
    size_t crops;
    virtual char getSign() { return 'S'; }
public:
    Structure(string name = "NO NAME", Point p = Point(), size_t c = 0): Sim_object{name,p}, crops{c} {}
    ~Structure() {}

    virtual void update(){}
};

#endif