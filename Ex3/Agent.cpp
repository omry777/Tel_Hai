#include "Agent.h"

bool Agent::Move() // returns true if Agent has reached it's destenation
{
    if (!health)
    {
        state = Dead;
        return false;
    }
    if (currDest != nullptr)
        destPoint = currDest->loc;
    else if (deg != 999)
        destPoint = loc.onCircle(speed, deg);

    state = Moving;
    if (loc.distanceFrom(destPoint) > speed)
        loc = loc.onCircle(speed, loc.getDegree(destPoint));
    else
        loc = destPoint;

    if (loc == destPoint)
    {
        state = Stopped;
        return true;
    }

    return false;
}

string Agent::getState() const
{
    switch (state)
    {
    case Dead:
        return "Dead";

    case Stopped:
        return "Stopped";

    case Moving:
        if (currDest != nullptr)
            return string("Heading to ") + currDest->name;
        else if (deg != 999)
            return string("Heading on course ") + to_string(deg) + string(" deg");
        else
            return string("Heading to ") + string("(") + to_string((int)destPoint.x) + string(".") + to_string(((int)(destPoint.x * 100) % 100)) + string(",") + to_string((int)destPoint.y) + string(".") + to_string(((int)(destPoint.y * 100) % 100)) + string(")");
    }
    return "No state found :(";
}

ostream &operator<<(ostream &out, const Agent &obj)
{
    return out << (Sim_object)obj << " , " << obj.getState();
}