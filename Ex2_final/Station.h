#ifndef STATION_H
#define STATION_H

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <cstring>
#include <string>
#include <iterator>
#include <algorithm>
#include <set>
#define MAX_STATIONS 1000

using namespace std;

typedef enum
{
    None = 0,
    Bus = 1,
    Tram = 2,
    Sprinter = 3,
    Rail = 5,
    All = 11
} TransportType;
typedef enum
{
    Central = 10,
    Intercity = 15,
    Stad = 5
} StationType;

class Station
{
private:
    string name;
    StationType type;
    map<TransportType, map<string, int>> dests;
    map<TransportType, map<string, int>> getHereFrom;
    friend class StGraph;

    StationType getType(string name);

public:
    Station()
    {
        dests = map<TransportType, map<string, int>>();
        getHereFrom = map<TransportType, map<string, int>>();
    };
    Station(string name);
    int findDest(string, TransportType);
    pair<size_t,TransportType> findDestTranspTime(string destName);
    string getName() { return name; }
    StationType getType(){ return type; }
    void addDest(TransportType, pair<string, int>);
    void printStation(ofstream&);
    ~Station();
};

std::ostream &operator<<(std::ostream &out, const TransportType value);
TransportType &operator++(TransportType &tt);
TransportType &operator++(TransportType &tt, int);

#endif