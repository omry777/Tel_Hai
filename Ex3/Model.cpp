#include "Model.h"

shared_ptr<Model>Model::m = nullptr;

Model::Model() : time(0) {}

void Model::addAgent(Sim_object *a)
{
    agentList.push_back((Agent *)a);
    AllList.push_back(a);
}


Model &Model::getInstance()  {
    if (m == nullptr) {
        m = make_shared<Model>();
        m->time = 0;
    }
    return *m;
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
    // attach();
    // v.draw();
}