/*
 * File: point.h
 * -------------
 * This interface exports a class representing an integer-valued x-y pair.
 */

#ifndef _point_h
#define _point_h

#include <ostream>
#include <string>

using namespace std;

class Point
{
private:
    float x;
    float y;

public:
    Point();
    Point(float x, float y);

    float getX() const;
    float getY() const;

    string toString() const;
    bool operator==(const Point &p2) const;
    bool operator!=(const Point &p2) const;
    Point & operator=(const Point &p2);
    Point &operator+(const Point &p2) const;
    Point &operator-(const Point &p2) const;
    Point &operator*(const float num) const;
    bool operator>(const Point &p2) const;
    bool operator<(const Point &p2) const;
};

std::ostream &operator<<(std::ostream &os, const Point &pt);

#endif