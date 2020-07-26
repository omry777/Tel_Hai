#ifndef STRUCTURES_H
#define STRUCTURES_H

#include "Sim_object.h"

class Structure : public Sim_object
{
protected:
    size_t crops;
    Structure *nearest;
    virtual char getSign() { return 'S'; }
    friend class Model;
    friend class Agent;
    friend ostream &operator<<(ostream &out, const Structure &obj);
public:
    Structure(string name = "NO NAME", Point p = Point(), size_t c = 0): Sim_object{name,p}, crops{c} {}
    ~Structure() {}

    virtual bool update(){ return true; }
    void print() {cout << *this << endl;}
};

ostream &operator<<(ostream &out, const Structure &obj);

#endif