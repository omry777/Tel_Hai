#include "Knight.h"

void Knight::startPatrol(Structure *h)
{
    home = h;
    notVisited.remove(home);
    if (loc != home->loc)
    {
        currDest = home;
    }
    else
    {
        currDest = findNearest();
    }
    state = Moving;
}
Structure *Knight::findNearest()
{
    Structure *near = notVisited.front();
    float d1, d2;
    for (auto &s : notVisited)
    {
        if ((d1 = loc.distanceFrom(near->loc)) > (d2 = loc.distanceFrom(s->loc)))
            near = s;
        if (d1 == d2 && s->name < near->name)
            near = s;
    }
    return near;
}

bool Knight::update()
{
    if (Move())
    {
        notVisited.remove(currDest);
        if (currDest == home && loc == currDest->loc)
        {
            state = Stopped;
            return true;
        }
        if (notVisited.empty())
        {
            currDest = home;
        }
        else
            currDest = findNearest();
        
        state  = Moving;
        return true;
    }

    return false;
}
ostream &operator<<(ostream &out, const Knight &obj)
{

    if (obj.state == Moving || obj.state == onCourse)
        return out << (Agent)obj << ", speed: " << obj.speed << " km/h";
    return out << (Agent)obj;
}