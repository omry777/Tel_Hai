#include "Model.h"
#include "Singleton.h"

int main(int argc, char *argv[])
{
    Model m = Singleton<Model>::getInstance();

    m.print();
    m.addAgent();
    m.addAgent(Agent("Gorge", Point(49, 0),Point(25,25)));
    m.addAgent(Peasant("John", Point(49, 49),Point(25,25)));
    m.addAgent(Peasant("Ringo", Point(25, 25),Point(25,25)));
    m.addAgent(Peasant("Paul", Point(0, 49),Point(25,25)));
    m.print();
    cout << "DONE!\n";
    string input;
    cin >> input;
    while (input != "quit"){
        m.moveAll();
        m.print();
        cin >> input;
    }

}