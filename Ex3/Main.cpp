#include "Model.h"
#include "Singleton.h"

int main(int argc, char *argv[])
{
    Model m = Singleton<Model>::getInstance();

    m.print();
    cout << "DONE!\n";
    m.addAgent();
    m.addAgent("Gorge", Point(49, 0));
    m.addAgent("John", Point(49,49));
    m.addAgent("Ringo", Point(25,25));
    m.addAgent("Paul", Point(0,49));
    cout << "DONE!\n";
    m.print();
    cout << "DONE!\n";
}