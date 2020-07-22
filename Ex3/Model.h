#ifndef MODEL_H
#define MODEL_H

#include "Peasant.h"
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
#define MAX_CROPS_TO_MOVE 5
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
    void addAgent(Sim_object *a);
    void addStructure(Sim_object *s);
    list<Sim_object *> &getAllList(){return AllList;}
    void update();
    bool setPeasantWork(string peasantName, string farmName, string castleName);
    Structure *findStructure(string name);
    Structure *findStructure(Point pos);
};

#endif