#include "Point.h"

Point::Point() { x = y = 0.0; }

Point::Point(float a, float b)
{
    x = a;
    y = b;
}

float Point::getX() const { return x; }

float Point::getY() const { return y; }

bool Point::operator==(const Point &p2) const{
    return (x == p2.x && y == p2.y);
}
bool Point::operator!=(const Point &p2) const{
    return !(x == p2.x && y == p2.y);
}
Point & Point::operator=(const Point &p2){
    x=p2.x;
    y=p2.y;
    return *this;
}

Point &Point::operator+(const Point &p2) const{
    return *(new Point(x+p2.x, y+p2.y));
}
Point &Point::operator-(const Point &p2) const{
    return *(new Point(x-p2.x, y-p2.y));
}
bool Point::operator>(const Point &p2) const{
    return x >= p2.x && y >= p2.y;
}
bool Point::operator<(const Point &p2) const{
    return x <= p2.x && y <= p2.y;
}
Point &Point::operator*(const float num) const{
    return *(new Point(x*num, y*num));
}

ostream &operator<<(ostream &os, const Point &pt){
    return os << "(" << pt.getX() << "," << pt.getY() << ")";
}
