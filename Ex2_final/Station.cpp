#include "Station.h"

Station::Station(string str)
{
    name = str;

    type = getType(str);
    getHereFrom = map<TransportType, map<string, int>>();
    dests = map<TransportType, map<string, int>>();

    for (TransportType tt = Bus; tt <= Rail; tt++)
    {
        dests.insert(make_pair(tt, map<string, int>()));
        getHereFrom.insert(make_pair(tt, map<string, int>()));
    }
}

void Station::addDest(TransportType tType, pair<string, int> st)
{
    dests.find(tType)->second.insert(st);
}

// returns the index of endStation in the apropriate line of dests
int Station::findDest(string endStation, TransportType type)
{
    pair<Station *const, int> temp;
    auto relMap = dests.find(type)->second;
    int i = 0;

    for (auto it = relMap.begin(); it != relMap.end(); it++)
    {
        if (strcmp(it->first.c_str(), endStation.c_str()))
        {
            return i;
        }
        i++;
    }
    return -1;
}

void Station::printStation(ofstream& outFile)
{
    
    outFile << "Station: " << name << endl;
    //cout << "---------Get To---------" << endl;
    for (auto it = dests.begin(); it != dests.end(); it++)
    {
        for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++)
            outFile << type << " " << name << " " << it->first << " " << it2->first << " " << it2->second << endl;
    }

    /*cout << "------Get Here From-------" << endl;
    for (auto it = getHereFrom.begin(); it != getHereFrom.end(); it++)
    {
        for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++)
            cout << type << " " << it2->first << " " << it->first << " " << name << " " << it2->second << endl;
    }*/
    outFile << endl;
}

StationType Station::getType(string name)
{
    string str = name.substr(0, 2);
    if (str == "IC")
        return Intercity;
    else if (str == "CS")
        return Central;
    else
        return Stad;
}

pair<size_t,TransportType> Station::findDestTranspTime(string destName){
    int num = 0;
    TransportType tType = None;
    map<string,int> revMap;
    for (TransportType tt = Bus; tt <= Rail; tt++){
        revMap = dests.find(tt)->second;
        for (auto it = revMap.begin(); it != revMap.end(); it++){
            if (!destName.compare(it->first)){
                if (num)
                    num = min(num,it->second);
                else
                    num = it->second;
                tType = tt;
            }
        }
    }
    return make_pair(num,tType);
}

std::ostream &operator<<(std::ostream &out, const TransportType value)
{
    string trans;
    switch (value)
    {
    case Bus:
        return out << "bus";
    case Tram:
        return out << "tram";
    case Sprinter:
        return out << "sprinter";
    case Rail:
        return out << "rail";
    case All:
        return out << "all";
    default:
        return out << "ERROR!";
    }
}
TransportType &operator++(TransportType &tt, int x)
{
    switch (tt)
    {
    case None:
        return (tt = Bus);
        break;
    case Bus:
        return (tt = Tram);
        break;
    case Tram:
        return (tt = Sprinter);
        break;
    case Sprinter:
        return (tt = Rail);
        break;
    case Rail:
        return (tt = All);
        break;
    case All:
        return (tt = None);
        break;
    }
    return tt;
}