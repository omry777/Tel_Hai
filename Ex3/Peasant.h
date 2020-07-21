#ifndef PEASANT_H
#define PEASANT_H

#include "Agent.h"

class Peasant : public Agent
{
private:
    Point src;
    Point dest;
public:
    Peasant(string name = "NO NAME", Point p = Point(), Point cd = Point(), float s = 0, size_t hp = 0, Point source = Point(), Point d = Point()): Agent{name,p,cd,s,hp} {src = source; dest = d; }
    ~Peasant(){};
};


#endif