#ifndef CASTLE_H
#define CASTLE_H
#include "Structure.h"

class Castle : public Structure
{
    friend class Model;

public:
    Castle(string name = "NO NAME", Point p = Point(), size_t c = 0) : Structure{name, p, c} {}
    ~Castle() {}
    char getSign() { return 'C'; }
};

#endif