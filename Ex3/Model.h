#ifndef MODEL_H
#define MODEL_H

#include "Sim_object.h"
#include "View.h"
#include <vector>
#define DEF_SIZE 100

#define VECTOR_TYPE (Sim_object *)

class Model
{
private:
    Sim_object *list[DEF_SIZE];
    size_t curr;

    View *v;

public:
    Model(/* args */) {curr = 0; v = new View(); };
    ~Model() { delete v; }

    void addAgent();
    void print()
    {
        attach();
        v->draw();
    }
    void attach() { v->setObjects(list, &curr); }
};

#endif