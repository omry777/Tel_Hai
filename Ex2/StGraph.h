#ifndef STGRAPH_H
#define STGRAPH_H

#include "Station.h"
#include <fstream>
#include <string>
#include <iterator>
#include <algorithm>
#include <vector>

class StGraph
{
private:
    vector<Station *> graph;
    size_t curr;
public:
    StGraph();
    StGraph(string fileName); //TODO (*) add configFile functionallity and infinite args (fileName) implemintation
    ~StGraph();
    void print(); //TODO (6) prints out the entire transportation system to the output File *******   V ********
    bool load(string fileName);  // V
    bool isExist(string startSt, string endSt);
    Station *find(string startSt); // V
    void printEverything(); // V

    // TODO (4) transit()       --Yair
    // TODO (5) multiTransit()  --Yair
    //      --vector<pair<vector<Station *>,size_t>> getListOfAllRoutes(TransportationType) //returnes a sorted list of <Station *station,size_t cost>
    //      -- probably better to return the least costly <Station *>
};

//TODO (*) Exceptions

#endif