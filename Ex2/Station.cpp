#include "Station.h"

// returns the index of endStation in the apropriate line of dests
int Station::findDest(string endStation, TransportType type){
    int i = 0;
    // auto &releventGraph = dests.find(type)->second;
    // for (auto &it : releventGraph)
    //     if (it.first->name.compare(endStation) == 0)
    //         return &it;
    pair<Station *const, int> temp;
    for (vector<pair<TransportType, pair<Station*, int>>>::iterator it = dests.begin(); it != dests.end(); it++){
        
        if (strcmp(it->second.first->name.c_str(), endStation.c_str()))
        {
            if( type = it->first){
                cout << "im here"<< endl;
                return i;
            }
        }
        
    }
    i++;
    return -1;
}

Station::Station(string str, TransportType TranT)
{
    switch (TranT) // This is useless, it's only for us to see the config file works. somehow
        {
        case 1:
            this->tranType = Bus;
            break;
        case 2:
            this->tranType = Tram;
            break;
        case 3:
            this->tranType = Sprinter;
            break;
        case 5:
            this->tranType = Rail;
            break;
        default:
            break;
        }
    name = str;
    // this->tranType = Bus;
    type = Central; //TODO findType() - get TT from str
    dests = vector<pair<TransportType,pair<Station*,int>>>(); 
}

void Station::addDest(TransportType type, pair<Station*, int> st){
    for (vector<pair<TransportType, pair<Station*, int>>>::iterator it = dests.begin(); it != dests.end(); it++)
    {
        // if(strcmp(it->first[0], type[0]))
    }
    dests.push_back(make_pair(type, st));
}

void Station::printStation(){
    string veichle ;
    for (vector<pair<TransportType, pair<Station*, int>>>::iterator it = dests.begin(); it != dests.end(); it++){
    switch (it->first) // This is useless, it's only for us to see the config file works. somehow
        {
        case 1:
            veichle = "bus";
            break;
        case 2:
            veichle = "tram";
            break;
        case 3:
            veichle = "sprinter";
            break;
        case 5:
            veichle = "rail";
            break;
        default:
            break;
        }
    cout << tranType << " " << type  << " "<< name << " " << veichle << " " << it->second.first->name << " " << it->second.second << endl;
    }


}