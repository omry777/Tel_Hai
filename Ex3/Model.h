#ifndef MODEL_H
#define MODEL_H

#include "Peasant.h"
#include "Knight.h"
#include "Thug.h"
#include "Farm.h"
#include "Castle.h"
#include <list>
#include <map>
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

    size_t time;
    friend class Controller;
public:
    Model();
    ~Model() {};
    static Model &getInstance();
    Model(const Model &) = delete;
    Model(Model &&) = delete;
    void addAgent(Agent *a);
    void addStructure(Structure *s);
    list<Sim_object *> &getAllList(){return AllList;}
    void update();
    bool isCloseEnough(Agent *a);
    bool findAgent(string);
    Agent *getAgent(string);
    bool setPeasantWork(string peasantName, string farmName, string castleName);
    Structure *findStructure(string name);
    Structure *findStructure(Point pos);
};

#endif