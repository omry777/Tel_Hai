#ifndef KNIGHT_H
#define KNIGHT_H

#include "Agent.h"
#include "Structure.h"

class Knight : public Agent
{
private:
    // Structure *dest;
    friend ostream &operator<<(ostream &out, const Knight &obj);
public:
    Knight(string name="NO NAME", Point p = Point()) : Agent{name,p,10,100}{} ;
    char getSign() { return 'K'; }
    ~Knight(){};


};
ostream &operator<<(ostream &out, const Knight &obj);




#endif