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
    void init(int argc, char* argv[]);
    void attach();
    ~Controller(){};
};



#endif