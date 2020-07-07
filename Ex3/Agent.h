#ifndef AGENT_H
#define AGENT_H
#include "Sim_object.h"

typedef enum {Stopped, Dead, Moving} State;

typedef struct{
    Point dest;
    float speed;
}moving_vars;

class Agent:public Sim_object
{
private:
    int health;
    State state;
    moving_vars otm; // On the move    
public:
    Agent(): Sim_object{} {};
    Agent(string name, Point loc, int health, State st ):Sim_object{name, loc}{this->health = health; state = st; };
    void move_to(Point dest);
    void update();
    ~Agent(){};
};

#endif