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
    Point(float a=0, float b=0) { x = a; y=b; };

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
    void *operator new(const size_t size){return malloc(sizeof(float)*2); };
};

std::ostream &operator<<(std::ostream &os, const Point &pt);

#endif