#ifndef MODEL_H
#define MODEL_H

#include "Peasant.h"
#include "Structure.h"
#include <list>
#include <mutex>
#include <vector>
#include <cmath>
#include <cstring>
#include <memory>

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
    list<Agent *> agentList;
    list<Structure *> structsList;
    list<Sim_object *> AllList;
    static shared_ptr<Model> m;


    // TODO: Add lists of Agents and Structures

    size_t time;
    // friend class Controller;

public:
    Model();
    ~Model() {};
    static Model &getInstance();
    Model(const Model &) = delete;
    Model(Model &&) = delete;
    void addAgent(Sim_object *a);
    void addStructure(Sim_object *s);
    list<Sim_object *> &getAllList(){return AllList;}
    void update();
    void print();
    // void attach() { v.setObjects(AllList); }
};

#endif