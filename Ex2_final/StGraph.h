#ifndef STGRAPH_H
#define STGRAPH_H

#include "Station.h"
#include <fstream>


typedef enum {out, in} Bounding;

class StGraph
{
private:
    vector<Station *> graph;
    size_t curr;
    size_t transpDiff[4];
    size_t stationDiff[3];

    set<string> getSet(Bounding bType, string station, TransportType tType, size_t jumps=0);
    void printSet(set<string> stSet, Bounding btype, TransportType tType);
    string boundAll(string stName, string soFar="\0");
    set<string> stringToSet(string str);
    bool isExist(string startSt, string endSt);
    string bound(Bounding fType, string stName, TransportType tType, int num=0);
    size_t costOfBestRoute(string startStation, TransportType tType, string endStation, int num=0);
    size_t getTranspIndex(TransportType tt);
    size_t getStationIndex(StationType tt);
public:
    StGraph();
    ~StGraph();
    
    void outbound(string stationName);//(2) v
    void inbound(string stationName);//(3) v
    bool load(string fileName); //(1) v
    Station *findStation(string);
    void printEverything(string); //(6) 
    void transit(string startStation, string endStation); //4 v
    size_t costOfBestRouteMixed(string startStation, string endStation, int num=0); //(5) v
    void setNewConfig(string fileName);
};
std::ostream &operator<<(std::ostream &out, const Bounding &value);

#endif