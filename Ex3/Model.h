#ifndef MODEL_H
#define MODEL_H

#include "View.h"
#include "Peasant.h"
#include <list>
#define DEF_SIZE 10

//TODO: Add Controller Class
//TODO: Add Agent (moving_object?) Class
//TODO: Add (Peasant,Knight,Thug)::Agent Class
//TODO: Add Structure Class
//TODO: Add (Castle, Farm)::Structure Class

using namespace std;

class Model
{
private:
    list<Agent> agentList;
    list<Sim_object *> AllList;

    // TODO: Add lists of Agents and Structures

    View v;
    size_t time;
    friend class View;

public:
    Model(/* args */) { v = *(new View()); }
    ~Model() {}

    void addAgent(Agent a = Agent()) { agentList.push_back(a); AllList.push_back(&agentList.back()); }
    void moveAll(){ for (auto &agent : agentList) agent.Move(); }
    void print();
    void attach() { v.setObjects(AllList); }
    //TODO Add detach();
    //TODO Add update()
    //TODO Add notify_location()
};

#endif