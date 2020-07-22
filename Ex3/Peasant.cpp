#include "Peasant.h"

void Peasant::update()
{
    if (Move())
    {
        if (loc == dest){
            //TODO: move packs to Castle
            currDest = src;
        }
        else{
            //TODO: get packs from Farm
            currDest = dest;
        }
    }
}