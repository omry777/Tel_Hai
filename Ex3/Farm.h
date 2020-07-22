#ifndef FARM_H
#define FARM_H

#include "Structure.h"

class Farm : public Structure
{
private:
    size_t growRate;
    char getSign() { return 'F'; }
    friend class Model;
    friend ostream &operator<<(ostream &out, const Farm &obj);
public:
    Farm(string name = "NO NAME",Point p = Point(), size_t gRate = 0) : Structure{name, p}, growRate{gRate} {}
    ~Farm() {}
    void print() { cout << *this << endl; }

    void update() { cout << crops << " + " << growRate << " = "; crops += growRate; cout << crops << endl; }
};
ostream &operator<<(ostream &out, const Farm &obj);


#endif