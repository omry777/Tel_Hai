#include "Sim_object.h"


Sim_object::Sim_object()
{
    name = "NO_NAME";
    location = Point();
}

Sim_object::Sim_object(string name, Point loc)
{
    this->name = name;
    location = loc;
}

Sim_object::~Sim_object()
{
}