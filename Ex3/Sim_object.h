#ifndef SIM_OBJECT_H
#define SIM_OBJECT_H

using namespace std;

class Sim_object
{
private:
    float x;
    float y;

    friend class View;
    friend class Model;
public:
    Sim_object(){ }
    ~Sim_object() { }
};

#endif