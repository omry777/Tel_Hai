#include "Model.h"

void Model::addAgent(Sim_object *a)
{
    agentList.push_back((Agent *)a);
    AllList.push_back(a);
}
void Model::addStructure(Sim_object *s)
{
    structsList.push_back((Structure*)s);
    AllList.push_back(s);
}
void Model::update()
{
    time++;
    for (auto &obj : AllList)
        obj->update();
}

void Model::print()
{
    attach();
    v.draw();
}