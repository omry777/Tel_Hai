#include "Sim_object.h"

Sim_object::Sim_object(string nm, float x, float y)
{
    name = nm;
    loc = Point(x, y);
}
ostream &operator<<(ostream &out, const Sim_object &obj) { out << obj.name << " at: " << obj.loc; }