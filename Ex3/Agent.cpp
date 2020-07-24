#include "Agent.h"

bool Agent::Move() // returns true if Agent has reached it's destenation
{
    if (loc == currDest->loc)
    {
        state = Stopped;
        return true;
    }

    state = Moving;
    Point diff;
    if (currDest != nullptr)
        diff = currDest->loc - loc;
    else
        diff = loc.onCircle(speed, deg) - loc;
    Point absDiff = abs(diff);

    diff /= absDiff;
    if (absDiff.x < speed)
        diff.x *= absDiff.x;
    else
        diff.x *= speed;

    if (absDiff.y < speed)
        diff.y *= absDiff.y;
    else
        diff.y *= speed;

    loc += diff;

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
        else
            return string("Heading on course %d deg", deg);
    }
    return "No state found :(";
}

ostream &operator<<(ostream &out, const Agent &obj)
{
    return out << (Sim_object)obj << ", HP: " << obj.health << " , " << obj.getState();
}