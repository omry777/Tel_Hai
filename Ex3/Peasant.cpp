#include "Peasant.h"

bool Peasant::update()
{
    if (Move())
    {
        if (dest != nullptr)
        {
            if (loc == dest->loc)
            {
                dest->crops += packs;
                packs = 0;
                currDest = src;
                health++;
            }
            else
            {
                if (src->crops > 0 && src->crops < MAX_CROPS_TO_MOVE)
                {
                    packs = src->crops;
                    src->crops = 0;
                }
                else
                {
                    packs = MAX_CROPS_TO_MOVE;
                    src->crops -= MAX_CROPS_TO_MOVE;
                }
                currDest = dest;
            }
        }
        return true;
    }
    return false;
}
ostream &operator<<(ostream &out, const Peasant &obj)
{
    return out << (Agent)obj << ", Inventory: " << obj.packs;
}