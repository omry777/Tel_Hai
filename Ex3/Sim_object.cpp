#include "Sim_object.h"

Sim_object::Sim_object(string nm, Point p)
{
    name = nm;
    loc = p;
}
ostream &operator<<(ostream &out, const Sim_object &obj) { return out << obj.name << " at: " << obj.loc; }