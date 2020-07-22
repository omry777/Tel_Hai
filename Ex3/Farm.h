#ifndef FARM_H
#define FARM_H

#include "Structure.h"

class Farm : public Structure
{
private:
    size_t growRate;
    char getSign() { return 'F'; }

public:
    Farm(string name = "NO NAME",Point p = Point(), size_t gRate = 0) : Structure{name, p}, growRate{gRate} {}
    ~Farm() {}

    void update() { crops += growRate; }
};

#endif