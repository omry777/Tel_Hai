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

    friend class Model;
    friend ostream &operator<<(ostream &out, const Peasant &obj);
public:
    Peasant(string name="NO NAME", Point p = Point(), float s = 5, size_t hp = 10): Agent{name,p,s,hp}, src{p}, dest{p} {}
    ~Peasant(){};

    void update();
    void print() {cout << *this << endl;}
};

ostream &operator<<(ostream &out, const Peasant &obj);


#endif