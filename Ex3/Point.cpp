#include "Point.h"

ostream &operator<<(ostream &os, const Point &pt)
{
    return os << "(" << pt.getX() << "," << pt.getY() << ")";
}
