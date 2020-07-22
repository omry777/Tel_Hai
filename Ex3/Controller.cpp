#include "Controller.h"
#include "Singleton.h"
#include "Farm.h"
#include "Castle.h"
using namespace std;

Controller::Controller() : v(new View()) {}

void Controller::attach()
{
    v->setObjects(Model::getInstance().getAllList());
}
void Controller::control()
{
    string input, input2;
    int num;
    float sc, x1, y1, x2, y2;
    
    do 
    {
        cout << "Time " << Model::getInstance().time << ": ";
        cin >> input;
        if (input == "default")
        {
            v->setSize(25);
            v->setScale(2);
        }
        else if (input == "show")
        {
            attach();
            v->draw();
        }
        else if (input == "size")
        {
            cin >> num;
            v->setSize(num);
        }
        else if (input == "zoom")
        {
            cin >> num;
            v->setScale(num);
        }
        else if (input == "create")
        {
            cin >> input >> x1 >> y1;
            Model::getInstance().addAgent(new Peasant(input, Point(x1, y2)));
        }
        else if (input == "go")
        {
            Model::getInstance().update();
        }
    }while (input != "exit");
}

void Controller::run()
{
    Model::getInstance().addStructure(new Farm("Manor Farm", Point(0, 0), 4));
    Model::getInstance().addStructure(new Farm("Animal Farm", Point(49, 49), 9));
    Model::getInstance().addStructure(new Farm("Foxwood Farm", Point(0, 49), 2));
    Model::getInstance().addStructure(new Farm("Pinchfield Farm", Point(49, 0), 3));
    Model::getInstance().addStructure(new Castle("White Castle", Point(25, 25)));
    Model::getInstance().addAgent(new Peasant("Gorge"));
    Model::getInstance().addAgent(new Peasant("John"));
    Model::getInstance().addAgent(new Peasant("Paul"));
    Model::getInstance().addAgent(new Peasant("Ringo"));
    Model::getInstance().setPeasantWork("Gorge", "Manor Farm", "White Castle");
    Model::getInstance().setPeasantWork("John", "Animal Farm", "White Castle");
    Model::getInstance().setPeasantWork("Paul", "Foxwood Farm", "White Castle");
    Model::getInstance().setPeasantWork("Ringo", "Pinchfield Farm", "White Castle");
    attach();
    v->draw();
    control();
}