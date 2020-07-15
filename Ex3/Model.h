#ifndef MODEL_H
#define MODEL_H

#include "View.h"
#include <list>
#define DEF_SIZE 10

//TODO: Add Controller Class
//TODO: Add Agent (moving_object?) Class
//TODO: Add (Peasant,Knight,Thug)::Agent Class
//TODO: Add Structure Class
//TODO: Add (Castle, Farm)::Structure Class

class Model
{
private:
    ListType list = {};
    // TODO: Add lists of Agents and Structures

    View v;
    size_t time;
    friend class View;

public:
    Model(/* args */) { v = *(new View()); }
    ~Model() {}

    void addAgent(string nm = "NO NAME", float x = 0, float y = 0) { list.push_front(Sim_object(nm, x, y)); }
    void print();
    void attach() { v.setObjects(list); }
    //TODO Add detach();
    //TODO Add update()
    //TODO Add notify_location()
};

#endif