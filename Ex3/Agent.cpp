#include "Agent.h"

bool Agent::Move() // returns true if Agent has reached it's destenation
{
    if (loc == currDest)
        return true;

    state = Moving;
    Point diff = currDest - loc;
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

    if (loc == currDest)
    {
        state = Stopped;
        return true;
    }
    return false;
}