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
        obj->update();
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
        cerr << "ERROR! can't find Peasant by the name of " << peasantName << endl;
        return false;
    }
    for (auto &s : structsList)
    {
        if (s->getSign() == 'F' && s->name == farmName)
        {
            peasant->src = (Farm *)s;
            
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
        cerr << "ERROR! can't find Farm by the name of " << farmName << endl;
    if (!f2)
        cerr << "ERROR! can't find Castle by the name of " << castleName << endl;

    if (peasant->packs == 0)
        peasant->currDest = peasant->src;
    else
        peasant->currDest = peasant->dest;

    if(f1 && f2 && peasant->currDest != nullptr)
        peasant->state = Moving;

    return f1 && f2;
}

bool Model::isCloseEnough(Agent* a){
    for (auto &obj : agentList){
        if(obj->getSign()=='K')
            if(obj->getLoc().distanceFrom(a->getLoc()) <= 2.5 && a->getName() != obj->getName()){
                cout << obj->getLoc().distanceFrom(a->getLoc()) << endl;
                return false;
            }
    }
    return true;
}