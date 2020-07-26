#include "Point.h"
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
    if (p2.x)
        x /= p2.x;
    else
        x = 0;
    if (p2.y)
        y /= p2.y;
    else
        y = 0;
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

float Point::distanceFrom(const Point &p) const
{
    return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
}

size_t Point::getDegree(const Point p)
{
    Point diff = p - *this;
    double temp = abs(atan(diff.y/ diff.x) * 180 / M_PI - 90);
    if (p.x < x)
        temp += 180;
    return temp;
}
ostream &operator<<(ostream &os, const Point &pt) { return os << "(" << pt.x << "," << pt.y << ")"; }
Point abs(Point p)
{
    p.x = (p.x > 0) ? p.x : -p.x;
    p.y = (p.y > 0) ? p.y : -p.y;
    return p;
}
