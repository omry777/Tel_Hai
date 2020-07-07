#include "Model.h"
Model *Model::instance = 0;

Model *Model::getInstance(){
    if (instance == 0)
        instance = new Model();
    
    return instance;
}

Model::Model()
{
    agentList = *(new vector<Agent>(MAX_SIZE));
    objList = *(new vector<Sim_object>(MAX_SIZE));
    strctList = *(new vector<Sim_object>(MAX_SIZE));
    cout << "WELLOW\n";
    v = *(new View(2,25));
    time = 0;
}

void Model::addAgent(string n){
    agentList[agentCurr++]= *(new Peasant());
    cout << "HI\n";
}


Model::~Model()
{
    delete &agentList;
    delete &strctList;
    delete &objList;
    delete &v;
}