#include "Model.h"

shared_ptr<Model> Model::m = nullptr;

Model::Model() : time(0) {}

Model &Model::getInstance()
{
    if (m == nullptr)
    {
        m = make_shared<Model>();
        m->time = 0;
    }
    return *m;
}
void Model::addAgent(Agent *a)
{

    agentList.push_back(a);
    AllList.push_back(a);
}

void Model::addStructure(Structure *s)
{
    structsList.push_back(s);
    AllList.push_back(s);
}

bool Model::findAgent(string name){
    for (auto &s : agentList)
        if (s->name == name)
            return true;
    return false;
}

Agent *Model::getAgent(string name){
    for (auto &s : agentList)
        if (s->name == name)
            return s;
    return nullptr;
}

Structure *Model::findStructure(string name){
    for (auto &s : structsList)
        if (s->name == name)
            return s;
    return nullptr;
}

Structure *Model::findStructure(Point pos){
    for (auto &s : structsList)
        if (s->loc == pos)
            return s;
    return nullptr;
}

void Model::update()
{
    time++;
    for (auto &obj : structsList)
        obj->update();

    for (auto &obj : agentList)
    {
        if (obj->update() && obj->getSign() == 'P' && ((Agent *)obj)->state == Stopped)
        {
            if (obj->loc == ((Peasant *)obj)->src->loc)
            {
                if (((Peasant *)obj)->src->crops == 0)
                    //obj->state = Moving;
                    break;
                else if (((Peasant *)obj)->src->crops < MAX_CROPS_TO_MOVE)
                {
                    ((Peasant *)obj)->packs = ((Peasant *)obj)->src->crops;
                    ((Peasant *)obj)->src->crops = 0;
                }
                else
                {
                    ((Peasant *)obj)->packs = MAX_CROPS_TO_MOVE;
                    ((Peasant *)obj)->src->crops -= MAX_CROPS_TO_MOVE;
                }
            }
            else if (obj->loc == ((Peasant *)obj)->dest->loc)
            {
                ((Peasant *)obj)->dest->crops += ((Peasant *)obj)->packs;
                ((Peasant *)obj)->packs = 0;
            }
        }
    }
}

bool Model::setPeasantWork(string peasantName, string farmName, string castleName)
{

    Peasant *peasant = nullptr;
    bool f1 = false, f2 = false;
    for (auto &p : agentList)
    {
        if (p->getSign() == 'P' && p->name == peasantName)
        {
            peasant = (Peasant *)p;
            break;
        }
    }
    if (peasant == nullptr)
    {
        cerr << "ERROR! can't find " << peasantName << endl;
        return false;
    }
    for (auto &s : structsList)
    {
        if (s->getSign() == 'F' && s->name == farmName)
        {
            peasant->src = (Farm *)s;
            peasant->currDest = s;
            f1 = true;
            if (f2)
                break;
        }
        else if (s->getSign() == 'C' && s->name == castleName)
        {
            peasant->dest = (Castle *)s;
            f2 = true;
            if (f1)
                break;
        }
    }
    if (!f1)
        cerr << "ERROR! can't find " << farmName << endl;
    if (!f2)
        cerr << "ERROR! can't find " << castleName << endl;

    if(f1 && f2 && peasant->currDest != nullptr)
        peasant->state = Moving;

    return f1 && f2;
}