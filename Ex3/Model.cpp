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
void Model::addAgent(Sim_object *a)
{

    agentList.push_back((Agent *)a);
    AllList.push_back(a);
}

void Model::addStructure(Sim_object *s)
{
    structsList.push_back((Structure *)s);
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
    map<Point, size_t> farms;
    map<Point, size_t> castles;
    for (auto &obj : structsList)
    {
        obj->update();
        // if (obj->getSign() == 'F')
        //     farms.insert(make_pair(obj->loc, ((Farm *)obj)->crops));
        // else if (obj->getSign() == 'C')
        //     castles.insert(make_pair(obj->loc, ((Castle *)obj)->crops));
    }
    Structure *it;
    for (auto &obj : agentList)
    {
        obj->update();
        if (obj->getSign() == 'P' && ((Agent *)obj)->state == Stopped)
        {
            if (obj->loc == ((Peasant *)obj)->src)
            {
                it = findStructure(obj->loc);
                if (it->crops == 0)
                    //obj->state = Moving;
                    break;
                else if (it->crops < MAX_CROPS_TO_MOVE)
                {
                    ((Peasant *)obj)->packs = it->crops;
                    it->crops = 0;
                }
                else
                {
                    ((Peasant *)obj)->packs = MAX_CROPS_TO_MOVE;
                    it->crops -= MAX_CROPS_TO_MOVE;
                }
            }
            else if (obj->loc == ((Peasant *)obj)->dest)
            {
                it = findStructure(obj->loc);
                it->crops += ((Peasant *)obj)->packs;
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
            peasant->src = s->loc;
            peasant->currDest = s->loc;
            f1 = true;
            if (f2)
                break;
        }
        else if (s->getSign() == 'C' && s->name == castleName)
        {
            peasant->dest = s->loc;
            f2 = true;
            if (f1)
                break;
        }
    }
    if (!f1)
        cerr << "ERROR! can't find " << farmName << endl;
    if (!f2)
        cerr << "ERROR! can't find " << castleName << endl;

    if(f1 && f2)
        peasant->state = Moving;

    return f1 && f2;
}