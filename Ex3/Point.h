/*
 * File: point.h
 * -------------
 * This interface exports a class representing an integer-valued x-y pair.
 */

#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <string>

using namespace std;

class Point
{
private:
    float x;
    float y;

public:
    Point(){ }
    Point(float a, float b)
    {
        cout << a <<  ", " << b << endl;
        x = a;
        y = b;
    };
    float getX() const { return x; }

    float getY() const { return y; }

    bool operator==(const Point &p2) const
    {
        return (x == p2.x && y == p2.y);
    }
    bool operator!=(const Point &p2) const
    {
        return !(*this == p2);
    }
    Point &operator=(const Point &p2)
    {
        x = p2.x;
        y = p2.y;
        return *this;
    }

    Point &operator+(const Point &p2) const
    {
        return *(new Point(x + p2.x, y + p2.y));
    }
    Point &operator-(const Point &p2) const
    {
        return *(new Point(x - p2.x, y - p2.y));
    }
    bool operator>(const Point &p2) const
    {
        return x >= p2.x && y >= p2.y;
    }
    bool operator<(const Point &p2) const
    {
        return x <= p2.x && y <= p2.y;
    }
    Point &operator*(const float num) const
    {
        return *(new Point(x * num, y * num));
    }
};

ostream &operator<<(ostream &os, const Point &pt);

#endif