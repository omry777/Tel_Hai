#ifndef PEASANT_H
#define PEASANT_H

#include "Agent.h"
#include "Farm.h"
#include "Castle.h"

class Peasant : public Agent
{
private:
    Farm *src;
    Castle *dest;
    size_t packs = 0;

    // char getSign() { return 'P'; }

    friend class Model;
    friend ostream &operator<<(ostream &out, const Peasant &obj);
public:
    Peasant(string name="NO NAME", Point p = Point(), float s = 5, size_t hp = 10): Agent{name,p,s,hp}, src{nullptr}, dest{nullptr} {}
    ~Peasant(){};
    char getSign() { return 'P'; }

    bool update();
    void print() {cout << *this << endl;}
};

ostream &operator<<(ostream &out, const Peasant &obj);


#endif