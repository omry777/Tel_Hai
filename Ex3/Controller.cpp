#include "Controller.h"
#include "Singleton.h"
#include "Farm.h"
#include "Castle.h"
using namespace std;


Controller::Controller() : v(new View()) {}

void Controller::attach(){
    v->setObjects(Model::getInstance().getAllList());
}
void Controller::control(){
    string input;
    int num;
    float sc;
    cin >> input;
    while(input != "exit"){
        if(input == "default"){
            v->setSize(25);
            v->setScale(2);
        }
        else if(input == "show"){
            attach();
            v->draw();
        }
        else if(input == "size"){
            cin >> num;
            v->setSize(num);
        }
        else if(input == "zoom"){
            cin >> num;
            v->setScale(num);
        }

        cin >> input;
    }
}

void Controller::run(){
    Model::getInstance().addAgent(new Peasant("Gorge", Point(0, 0),Point(25,25), Point(0, 0),Point(25,25)));
    Model::getInstance().addAgent(new Peasant("John", Point(49, 49),Point(25,25),Point(49,49),Point(25,25)));
    Model::getInstance().addAgent(new Peasant("Paul", Point(0, 49),Point(25,25), Point(0, 49),Point(25,25)));
    Model::getInstance().addAgent(new Peasant("Ringo", Point(49, 0),Point(25,25), Point(49, 0),Point(25,25)));
    attach();
    v->draw();
    Model::getInstance().addStructure(new Farm("Manor Farm",Point(0,0),4));
    Model::getInstance().addStructure(new Farm("Animal Farm",Point(49,49),9));
    Model::getInstance().addStructure(new Farm("Foxwood Farm",Point(0,49),2));
    Model::getInstance().addStructure(new Farm("Pinchfield Farm",Point(49,0),3));
    Model::getInstance().addStructure(new Castle("White Castle", Point(25,25)));
    attach();
    v->draw();
    control();
}