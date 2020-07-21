#ifndef AGENT_H
#define AGENT_H

#include "Point.h"
#include "Sim_object.h"

typedef enum
{
    Dead,
    Moving,
    Stopped
} StateType;

class Agent : public Sim_object
{
protected:
    Point currDest;
    float speed;
    size_t health;
    StateType state;

public:
    Agent(string name = "NO NAME", Point p = Point(), Point d = Point(), float s = 0, size_t hp = 0) : Sim_object{name, p}
    {
        currDest = d;
        speed = s;
        health = hp;
    };
    ~Agent(){};

    void setDest(Point dest) { currDest = dest; }
    bool Move();
};

#endif