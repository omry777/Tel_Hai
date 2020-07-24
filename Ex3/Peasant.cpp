#include "Peasant.h"

bool Peasant::update()
{
    if (Move())
    {
        if (loc == dest->loc)
        {
            currDest = src->loc;
            health++;
        }
        else
            currDest = dest->loc;
        return true;
    }
    return false;
}
ostream &operator<<(ostream &out, const Peasant &obj)
{
    return out << (Agent)obj << ", Inventory: " << obj.packs;
}