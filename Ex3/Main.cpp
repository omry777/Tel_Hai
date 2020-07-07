#include "Model.h"

using namespace std;

int main(int argc, char *argv[]){
    Model *m = Model::getInstance();
    cout << "DONE!\n";
    m->addAgent("peasant");
    m->print();
}