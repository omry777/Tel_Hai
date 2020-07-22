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

    virtual char getSign() { return 'A'; }
    bool Move();

    friend class Model;
    friend ostream &operator<<(ostream &out, const Agent &obj);
public:
    Agent(string name="NO NAME",Point p = Point(),  float s = 0, size_t hp = 0) : Sim_object{name,p}, currDest{p}, speed{s}, health{hp}, state{Moving} {}
    ~Agent(){};

    void setDest(Point dest) { currDest = dest; }
    virtual void print() {cout << *this << endl;}
    virtual void update() { Move(); }
};
ostream &operator<<(ostream &out, const Agent &obj);

#endif