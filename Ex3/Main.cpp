#include "Model.h"
#include "Singleton.h"
#include "Farm.h"
#include "Castle.h"
#include "Controller.h"

int main(int argc, char *argv[])
{
    Controller c;
    c.init(argc, argv);
    c.run();
    cout << "DONE!\n";

}