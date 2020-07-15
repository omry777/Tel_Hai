#include "Point.h"
Point::Point(float a, float b)
{
    x = a;
    y = b;
}
Point &Point::operator=(const Point &p2)
{
    x = p2.x;
    y = p2.y;
    return *this;
}
Point &Point::operator+=(const Point &p2)
{
    x += p2.x;
    y += p2.y;
    return *this;
}
Point &Point::operator-=(const Point &p2)
{
    x -= p2.x;
    y -= p2.y;
    return *this;
}
Point &Point::operator+=(const float &num)
{
    x += num;
    y += num;
    return *this;
}
Point &Point::operator-=(const float &num)
{
    x -= num;
    y -= num;
    return *this;
}
Point &Point::operator*=(const Point &p2)
{
    x *= p2.x;
    y *= p2.y;
    return *this;
}
Point &Point::operator/=(const Point &p2)
{
    x /= p2.x;
    y /= p2.y;
    return *this;
}
Point &Point::operator*=(const float &num)
{
    x *= num;
    y *= num;
    return *this;
}
Point &Point::operator/=(const float &num)
{
    x /= num;
    y /= num;
    return *this;
}

ostream &operator<<(ostream &os, const Point &pt) { return os << "(" << pt.x << "," << pt.y << ")"; }
