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
    // Model &m = Singleton<Model>::getInstance();
public:
    Controller();
    // void default_size(){v->setScale(2); v->setSize(25);};
    // void show(){v->draw();}
    // void change_size(int n){v->setSize(n);}
    void control();
    void run();
    void attach();
    ~Controller(){};
};



#endif