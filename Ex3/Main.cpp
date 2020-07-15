#include "Model.h"
#include "Singleton.h"

int main(int argc, char *argv[])
{
    Model m = Singleton<Model>::getInstance();

    m.print();
    cout << "DONE!\n";
    m.addAgent("NO NAME", 25,25);
    m.addAgent("Gorge", 49, 0);
    m.addAgent("John", 49,49);
    m.addAgent("Ringo", 0,0);
    m.addAgent("Paul", 0,49);
    cout << "DONE!\n";
    m.print();
    cout << "DONE!\n";
}