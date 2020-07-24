#ifndef SIM_OBJECT_H
#define SIM_OBJECT_H

#include "Point.h"
#include <string>

using namespace std;

class Sim_object
{
protected:
    string name;
    Point loc;
    

    virtual char getSign() { return 's'; }

    friend class View;
    friend class Model;
    friend ostream &operator<<(ostream &out, const Sim_object &obj);

public:
    Sim_object(string nm = "NO NAME", Point p= Point()) : loc{p}, name{nm} {}
    ~Sim_object() { }

    string getName() { return name; }
    virtual void print() {cout << *this << endl;}
    virtual bool update(){ return true; }
    Point getLoc(){return loc;}
};
ostream &operator<<(ostream &out, const Sim_object &obj);

#endif