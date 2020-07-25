#ifndef THUG_H
#define THUG_H

#include "Agent.h"
#include "Structure.h"

class Thug : public Agent
{
private:
    // Structure *dest;
    friend ostream &operator<<(ostream &out, const Thug &obj);
public:
    Thug(string name="NO NAME", Point p = Point()) : Agent{name,p,0,5}{} ;
    char getSign() { return 'T'; }
    void print() {cout << *this << endl;}
    ~Thug(){};


};
ostream &operator<<(ostream &out, const Thug &obj);




#endif