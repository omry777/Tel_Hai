#ifndef KNIGHT_H
#define KNIGHT_H

#include "Agent.h"
#include "Structure.h"

class Knight : public Agent
{
private:
    // Structure *dest;
    char getSign() { return 'K'; }
    friend ostream &operator<<(ostream &out, const Knight &obj);
public:
    Knight(string name="NO NAME", Point p = Point()) : Agent{name,p,10,100}{} ;
    ~Knight(){};
};
ostream &operator<<(ostream &out, const Knight &obj);




#endif