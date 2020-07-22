#ifndef PEASANT_H
#define PEASANT_H

#include "Agent.h"

class Peasant : public Agent
{
private:
    Point src;
    Point dest;
    size_t packs = 0;

    char getSign() { return 'P'; }
public:
    Peasant(string name="NO NAME", Point p = Point(), Point cd = Point(), Point source = Point(), Point d = Point(), float s = 5, size_t hp = 10): Agent{name,p,cd,s,hp} {src = source; dest = d; }
    ~Peasant(){};

    void update();
};


#endif