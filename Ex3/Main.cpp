#include "Model.h"
#include "Singleton.h"
#include "Farm.h"
#include "Castle.h"
#include "Controller.h"

int main(int argc, char *argv[])
{
    Controller c;
    c.run();
    // Model m = Singleton<Model>::getInstance();

    cout << "DONE!\n";
    // string input;
    // cin >> input;
    // while (input != "quit"){
    //     // m.update();
    //     // m.print();
    //     cin >> input;
    // }

}