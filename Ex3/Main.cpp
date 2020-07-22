#include "Model.h"
#include "Singleton.h"
#include "Farm.h"
#include "Castle.h"

int main(int argc, char *argv[])
{
    Model m = Singleton<Model>::getInstance();

    m.print();
    m.addAgent(new Peasant("Gorge", Point(0, 0),Point(25,25), Point(0, 0),Point(25,25)));
    m.addAgent(new Peasant("John", Point(49, 49),Point(25,25),Point(49,49),Point(25,25)));
    m.addAgent(new Peasant("Paul", Point(0, 49),Point(25,25), Point(0, 49),Point(25,25)));
    m.addAgent(new Peasant("Ringo", Point(49, 0),Point(25,25), Point(49, 0),Point(25,25)));
    m.addStructure(new Farm("Manor Farm",Point(0,0),4));
    m.addStructure(new Farm("Animal Farm",Point(49,49),9));
    m.addStructure(new Farm("Foxwood Farm",Point(0,49),2));
    m.addStructure(new Farm("Pinchfield Farm",Point(49,0),3));
    m.addStructure(new Castle("White Castle", Point(25,25)));
    m.print();
    cout << "DONE!\n";
    string input;
    cin >> input;
    while (input != "quit"){
        m.update();
        m.print();
        cin >> input;
    }

}