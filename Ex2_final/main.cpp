#include "StGraph.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <stdio.h>
#include <exception>

using namespace std;

int main(int argc, char *argv[])
{
    StGraph graph = StGraph();
    string chs = "", temp, temp2;
    string outFileName = "output.dat";
    bool wasI = false;
    if(argc < 2){
        cerr << "Not enough args" << endl;
        exit(1);
    }
    for (size_t i = 1; i < (unsigned)argc; i++)
    {
        if (strcmp(argv[i], "-i") == 0)
        {
            wasI = true;
            for (size_t j = i+1; j < (unsigned)argc; j++) 
            {
                if(strcmp(argv[j], "-c") == 0 || strcmp(argv[j], "-o") == 0)
                    break;
                cout << argv[j] << endl;
                try {
                    graph.load(argv[j]);
                }catch(const char * e){
                    cerr << e <<  endl;
                    exit(1);
                }   
                    
            }
        }
        if(strcmp(argv[i], "-c") == 0){
            try{
                ifstream config(argv[i+1]);
			    if(!config.is_open()) {
				    throw exception();
			    }

                graph.setNewConfig(argv[i+1]);

            } catch (exception){
                cerr << "ERROR opening the specified file." <<  endl;
            }
        }
        if(strcmp(argv[i], "-o") == 0){
            try{
                ifstream outputFile(argv[i+1]);
			    if(!outputFile.is_open()) {
				    throw exception();
			    }

                outFileName = argv[i+1];

            } catch (exception){
                cerr << "ERROR opening the specified file." <<  endl;
            }
        }
    }

    if (!wasI)
    {
        cerr << "No input files !" << endl;
        exit(1);
    }
    
    do
    {
        cout << ">";
        cin >> chs;
        if (chs == "load")
        {
            cin >> temp;
            try {
                graph.load(temp);
            } catch (char const *  st){
                cout << st << endl;
                // cerr << "ERROR opening the specified file." <<  endl;
            }
        }
        else if (chs == "outbound")
        {
            cin >> temp;
            graph.outbound(temp);
        }
        else if (chs == "inbound")
        {
            cin >> temp;
            graph.inbound(temp);
        }else if (chs == "uniExpress")
        {
            cin >> temp >> temp2;
            graph.transit(temp, temp2);
        }else if (chs == "multiExpress")
        {
            cin >> temp >> temp2;
            size_t len = graph.costOfBestRouteMixed(temp, temp2);
            if (len != 0){
                len -= graph.findStation(temp)->getType();
            cout << "Best route is " << len << " minutes long" << endl;
            }else
                cout << "Route not found" << endl;
        }else if (chs == "print")
        {
            graph.printEverything(outFileName);
        }else if (chs != "QUIT"){
            cerr << "ERROR! NO VALID INPUT!" << endl;
        }
    } while (chs != "QUIT");
};
