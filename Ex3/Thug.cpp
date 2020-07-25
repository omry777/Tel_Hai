#include "Thug.h"

ostream &operator<<(ostream &out, const Thug &obj)
{
    if(obj.state == Moving || obj.state == onCourse)
        return out << (Agent)obj << ", speed: " << obj.speed << " km/h";
    return out << (Agent)obj;
}