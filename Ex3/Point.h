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

    friend ostream &operator<<(ostream &os, const Point &pt);
    friend Point abs(Point p);
    friend class Agent;
public:
    Point(float a = 0, float b = 0);
    float getX() const { return x; }
    float getY() const { return y; }

    Point &operator=(const Point &p2);
    Point &operator+=(const Point &p2);
    Point &operator-=(const Point &p2);
    Point &operator+=(const float &num);
    Point &operator-=(const float &num);
    Point &operator*=(const Point &p2);
    Point &operator/=(const Point &p2);
    Point &operator*=(const float &num);
    Point &operator/=(const float &num);
    bool operator==(const Point &p2) const { return (x == p2.x && y == p2.y); }
    bool operator!=(const Point &p2) const { return !(*this == p2); }
    bool operator==(const float &num) const { return *this == Point(num,num); }
    bool operator!=(const float &num) const { return !(*this == num); }
    bool operator>(const Point &p2) const { return x > p2.x && y > p2.y; }
    bool operator<(const Point &p2) const { return x < p2.x && y < p2.y; }
    bool operator>(const float num) const { return x > num && y > num; }
    bool operator<(const float num) const { return x < num && y < num; }
    bool operator>=(const Point &p2) const { return !(*this < p2); }
    bool operator<=(const Point &p2) const { return !(*this > p2); }
    bool operator>=(const float num) const { return !(*this < Point(num,num)); }
    bool operator<=(const float num) const { return !(*this > Point(num,num)); }
    Point &operator+(const Point &p2) const { return *(new Point(x + p2.x, y + p2.y)); }
    Point &operator-(const Point &p2) const { return *(new Point(x - p2.x, y - p2.y)); }
    Point &operator*(const Point &p2) const { return *(new Point(x * p2.x, y * p2.y)); }
    Point &operator/(const Point &p2) const { return *(new Point(x / p2.x, y / p2.y)); }
    Point &operator*(const float num) const { return *(new Point(x * num, y * num)); }
    Point &operator/(const float num) const { return *(new Point(x / num, y / num)); }
};

ostream &operator<<(ostream &os, const Point &pt);

#endif