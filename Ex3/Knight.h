#ifndef KNIGHT_H
#define KNIGHT_H

#include "Agent.h"
#include "Structure.h"
#include <list>

class Knight : public Agent
{
private:
    Structure *home;
    list<Structure *> notVisited;
    friend ostream &operator<<(ostream &out, const Knight &obj);
public:
    Knight(list<Structure *> structures, string name="NO NAME", Point p = Point()) : Agent{name,p,10,100}, notVisited{structures} {} ;
    void startPatrol(Structure *h);
    Structure *findNearest();
    bool update();
    char getSign() { return 'K'; }
    void print() {cout << *this << endl;}
    ~Knight(){};


};
ostream &operator<<(ostream &out, const Knight &obj);




#endif