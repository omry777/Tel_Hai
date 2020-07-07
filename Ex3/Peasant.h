#ifndef PEASENT_H
#define PEASENT_H
#include "Agent.h"


class Peasant: public Agent
{
public:
    Peasant(): Agent{} {};
    Peasant(string name, Point loc, int health, State st): Agent{ name,  loc,  health, st } {};
    ~Peasant() { };
};




#endif