#ifndef FARM_H
#define FARM_H

#include "Structure.h"

class Farm : public Structure
{
private:
    size_t growRate;
    char getSign() { return 'F'; }
    friend class Model;
    friend class Peasant;
    friend ostream &operator<<(ostream &out, const Farm &obj);
public:
    Farm(string name = "NO NAME",Point p = Point(), size_t crops = 0 , size_t gRate = 0 ) : Structure{name, p, crops}, growRate{gRate} {}
    ~Farm() {}
    void print() { cout << *this << endl; }

    bool update() { crops += growRate; return true; }
};
ostream &operator<<(ostream &out, const Farm &obj);


#endif