#ifndef MODEL_H
#define MODEL_H

#include "View.h"
#include "Peasant.h"

class Model
{
private:
    static Model *instance;
  
    vector<Sim_object *> objList;
    int objCurr = 0;
    vector<Agent *> agentList;
    int agentCurr = 0;
    vector<Sim_object *> strctList; //vector<Struct>
    int strctCurr = 0;
    View *v;
    int time;
    Model();
public:
    static Model *getInstance();
    void addAgent(string n);
    void update();
    void attach(){v->setObjects(&objList, &objCurr); };
    void detach();
    void print(){attach(); v->draw();}
    ~Model();
};

#endif