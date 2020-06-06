#include "StGraph.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstring>


using namespace std;

int main(int argc, char* argv[]){
    StGraph graph;
    for (size_t i = 1; i < argc; i++)
    {
        if(strcmp(argv[i],"-i")==0){
            // graph.load(argv[i+1]);
            for (size_t j = i+1; j < argc; j++)
            {
                cout << argv[j] << endl;
                graph.load(argv[j]);
            }
            

        }
        // else{
        //     cout << "Unrecognized argument" << endl;
        // }
    }
    
    graph.printEverything();
    cout << "done" << endl;
};
    
    
