#include "Model.h"

using namespace std;

int main(int argc, char *argv[]){
    Model *m = Model::getInstance();
    m->addAgent("peasant");
    m->print();
}