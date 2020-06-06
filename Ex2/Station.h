#ifndef STATION_H
#define STATION_H

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstring>

using namespace std;

typedef enum {Bus=1, Tram=2, Sprinter=3, Rail=5} TransportType;
typedef enum {Central = 10, Intercity = 15, Stad = 5} StationType ;

class Station
{
private:
    string name;
    StationType type;
    TransportType tranType;
    // map<TransportType, map<Station *,int>> dests;
    vector<pair<TransportType,pair<Station*,int>>> dests;
    vector<Station *> getHereFrom; //TODO all the stations you can get to this station from
    friend class StGraph;
public:
    Station(){dests = vector<pair<TransportType,pair<Station*,int>>>(1000); getHereFrom = vector<Station *>(1000);};
    Station(string name, TransportType);
    int findDest(string, TransportType);
    string getName(){return name;}
    void addDest(TransportType, pair<Station* , int>);
    void printStation();
    //Station* findStation(Station*);
    void printOutound(size_t num); //TODO (2) prints all the dests you can get to (up to num jumps) // Kind of finished
    void printInbound(size_t num); //TODO (3) prints all the stations you can get from to here(up to num jumps)
    ~Station();

    
    
};


#endif