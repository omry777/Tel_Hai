#include "Peasant.h"

bool Peasant::update()
{
    if (Move())
    {
        cerr << "HI\n";
        if (dest != nullptr)
            if (loc == dest->loc)
            {
                currDest = src;
                health++;
            }
            else
                currDest = dest;
        return true;
    }
    return false;
}
ostream &operator<<(ostream &out, const Peasant &obj)
{
    return out << (Agent)obj << ", Inventory: " << obj.packs;
}