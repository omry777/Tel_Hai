#ifndef AGENT_H
#define AGENT_H

#include "Point.h"
#include <sstream>
#include <string.h>
#include "Structure.h"

typedef enum
{
    Dead,
    Moving,
    onCourse,
    Stopped
} StateType;

class Agent : public Sim_object
{
protected:
    Structure *currDest;
    int deg;
    float speed;
    size_t health;

    StateType state;

    virtual char getSign() { return 'A'; }
    bool Move();

    friend class Model;
    friend ostream &operator<<(ostream &out, const Agent &obj);

public:
    Agent(string name = "NO NAME", Point p = Point(), float s = 0, size_t hp = 0) : Sim_object{name, p}, currDest{nullptr}, speed{s}, health{hp}, state{Stopped}, deg{999} {}
    ~Agent(){};

    void setDest(Structure *dest)
    {
        currDest = dest;
        deg = 999;
    }
    void setCourse(float degr)
    {
        deg = degr;
        currDest = nullptr;
    }
    void setSpeed(float s) { speed = s; }
    void stop()
    {
        currDest = nullptr;
        deg = 999;
        state = Stopped;
    }
    string getState() const;
    virtual void print() { cout << *this << endl; }
    virtual bool update() { return Move(); }
};
ostream &operator<<(ostream &out, const Agent &obj);

#endif