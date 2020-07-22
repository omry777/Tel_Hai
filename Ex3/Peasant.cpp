#include "Peasant.h"

void Peasant::update()
{
    if (Move())
    {
        if (loc == dest)
        {
            currDest = src;
            health++;
        }
        else
            currDest = dest;
    }
}
ostream &operator<<(ostream &out, const Peasant &obj)
{
    return out << (Agent)obj << " Inventory: " << obj.packs;
}