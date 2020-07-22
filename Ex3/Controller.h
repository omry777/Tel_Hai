#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "View.h"
#include <map>
#include <iterator>
#include <algorithm>
#include <cstring>

class Controller
{
private:
    View *v;
public:
    Controller();
    void control();
    void run();
    void attach();
    ~Controller(){};
};



#endif