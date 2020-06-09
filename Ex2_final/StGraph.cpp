#include "StGraph.h"

StGraph::StGraph()
{
    this->graph = vector<Station *>(100);
    this->curr = 0;
}

void StGraph::setNewConfig(string fileName){
    ifstream configFile(fileName);
    string token;
    string newNum;
    int num;
    
    while (!configFile.eof())
    {
        getline(configFile,  token , '\t');
        getline(configFile, newNum, '\t');
        num = stoi(newNum);

        if (token == "bus"){
            transpDiff[0] = num-Bus;
        }else if (token == "tram"){
            transpDiff[1] = num-Tram;
        }else if (token == "sprinter"){
            transpDiff[2] = num-Sprinter;
        }else if (token == "rail"){
            transpDiff[3] = num-Rail;
        }else if (token == "centraal"){
            stationDiff[0] = num-Central;
        }else if (token == "intercity"){
            stationDiff[1] = num-Intercity;
        }else if (token == "stad"){
            stationDiff[2] = num-Stad;
        }else
        {
            cerr << "ERROR! invalid config" << endl;
        }
        
    }

}

bool StGraph::load(string fileName) //throws FILE exception?
{
    ifstream file(fileName);

    if (!file.is_open()) //TODO check if opened
    {
        throw "ERROR opening the specified file.";
    }

    TransportType type;
    switch (fileName[0])
    {
    case 'b':
        type = Bus;
        break;
    case 't':
        type = Tram;
        break;
    case 's':
        type = Sprinter;
        break;
    case 'r':
        type = Rail;
        break;

    default:
        break;
    }

    string startSt, endSt, sTime;
    int time;
    int j = -1;
    Station *st, *st2;
    pair<Station *const, int> p;

    while (!file.eof())
    {
        getline(file, startSt, '\t');
        getline(file, endSt, '\t');
        getline(file, sTime, '\n');
        time = stoi(sTime);

        if ((st = findStation(startSt)) != nullptr)
        {
            if ((j = st->findDest(endSt, type)) != -1) // Check if it this destination is already exists. if doesn't returns -1.
            {
                auto time2 = st->dests.find(type)->second.find(endSt);
                if (time < time2->second)
                    time2->second = time;
            }
            else
            {
                st2 = findStation(endSt);
                if (st2 == nullptr)
                {
                    st2 = new Station(endSt);
                    graph[curr++] = st2;
                }
                st->addDest(type, make_pair(st2->name, time));
            }
        }
        else
        {
            st = new Station(startSt);
            graph[curr++] = st;

            st2 = findStation(endSt);
            if (st2 == nullptr)
            {
                st2 = new Station(endSt);
                graph[curr++] = st2;
            }
            st->addDest(type, make_pair(st2->name, time));
        }
        st2->getHereFrom.find(type)->second.insert(make_pair(st->name, time));
    }

    return true;
}

Station *StGraph::findStation(string startSt)
{
    for (size_t i = 0; i < curr; i++)
    {
        if (graph.at(i)->name.compare(startSt) == 0)
            return graph.at(i);
    }
    return nullptr;
}

void StGraph::printEverything(string fileName)
{
    ofstream myfile;
    myfile.open(fileName);
    for (size_t i = 0; i < curr; i++)
    {
        graph[i]->printStation(myfile);
    }
    myfile.close();
}

string StGraph::bound(Bounding fType, string stName, TransportType tType, int num)
{
    string temp = "";
    Station *st = findStation(stName);
    if (st == nullptr)
        return "ERROR!";
    map<TransportType, map<string, int>> *revMap;

    if (fType == in)
        revMap = &st->getHereFrom;
    else
        revMap = &st->dests;
    
    if (tType == All)
    {
        for (TransportType tt = Bus; tt <= Rail; tt++)
        {
            for (auto it2 = revMap->find(tt)->second.begin(); it2 != revMap->find(tt)->second.end(); it2++)
            {
                temp += it2->first;
                temp += "\t";
            }
        }
    }
    else
    {
        auto it = revMap->find(tType);
        for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++)
            {
                temp += it2->first;
                temp += "\t";
                if (num > 1)
                {
                    temp += bound(fType, it2->first, tType, num - 1);
                }
            }
    }
    
    return temp;
}
string StGraph::boundAll(string stName, string soFar)
{
    Station *st = findStation(stName);
    if (st == nullptr)
        return "ERROR!";
    map<string, int> revMap;
    for (TransportType tt = Bus; tt <= Rail; tt++)
    {
        revMap = st->dests.find(tt)->second;
        for (auto it = revMap.begin(); it != revMap.end(); it++)
        {
            if (soFar.find(it->first) == string::npos)
            {
                soFar += it->first + "\t";
                soFar += boundAll(it->first, soFar);
            }
        }
    }
    return soFar;
}
void StGraph::outbound(string stationName)
{
    Station *st;
	  if((st = findStation(stationName)) == nullptr){
		cerr << "does not exist in the current network." << endl;
		return;
	  }
    for (TransportType tt = Bus; tt <= Rail; tt++)
        printSet(getSet(out, stationName, tt), out, tt);
    cout << endl;
}
void StGraph::inbound(string stationName)
{
    Station *st;
	  if((st = findStation(stationName)) == nullptr){
		cerr << "does not exist in the current network." << endl;
		return;
 	}
    for (TransportType tt = Bus; tt <= Rail; tt++)
        printSet(getSet(in, stationName, tt), in, tt);
    cout << endl;
}
set<string> StGraph::stringToSet(string str)
{
    size_t len;
    string temp;
    set<string> stSet = set<string>();
    while ((len = str.find('\t')) != string::npos)
    {
        temp = str.substr(0, len);
        str = str.substr(len + 1, str.length());
        stSet.insert(temp);
    }
    return stSet;
}

set<string> StGraph::getSet(Bounding bType, string station, TransportType tType, size_t jumps)
{
    if (jumps == 0)
        jumps = curr;
    if (tType != All)
        return stringToSet(bound(bType, station, tType, jumps));
    else
    {
        if (jumps == curr)
            return stringToSet(boundAll(station));
        else
            return stringToSet(bound(bType, station, tType, jumps));
    }
}

void StGraph::printSet(set<string> stSet, Bounding bType, TransportType tType)
{
    cout << tType << ": ";
    if (stSet.empty())
    {
        cout << "no " << bType << "bound travel" << endl;
        return;
    }

    for (auto it = stSet.begin(); it != stSet.end(); it++)
        cout << *it << "\t";

    cout << endl;
}
void StGraph::transit(string startStation, string endStation)
{
    size_t sum = 0;

    for (TransportType tt = Bus; tt <= Rail; tt++)
    {
        cout << tt << ": ";
        if (!startStation.compare(endStation))
        {
            cout << 0 << endl;
        }
        else
        {
            sum = costOfBestRoute(startStation, tt, endStation);
            if (sum != 0)
            {
                sum -= findStation(startStation)->type;
                cout << sum << endl;
            }
            else
                cout << "route unavailable" << endl;
        }
    }
    cout << endl;
}
size_t StGraph::costOfBestRoute(string startStation, TransportType tType, string endStation, int num)
{
    if (num == 0)
        num = curr;
    int sum = 0, sum2;
    set<string> ava;
    ava = getSet(out, startStation, tType);
    if (ava.find(endStation) == ava.end())
    {
        return 0;
    }

    Station *st = findStation(startStation);

    auto &revMap = st->dests.find(tType)->second;
    auto itP = revMap.find(endStation);
    if (itP != revMap.end())
    {
        return itP->second + findStation(endStation)->type + transpDiff[getTranspIndex(tType)] + stationDiff[getStationIndex(st->type)];
    }

    for (auto it = revMap.begin(); it != revMap.end(); it++)
    {
        if (sum == 0)
        {
            sum = costOfBestRoute(it->first, tType, endStation) + it->second + findStation(it->first)->type + transpDiff[getTranspIndex(tType)] + stationDiff[getStationIndex(st->type)]; //TODO add the diff of  defaults waiting time
        }
        else
        {
            sum2 = costOfBestRoute(it->first, tType, endStation) + it->second + findStation(it->first)->type + transpDiff[getTranspIndex(tType)] + stationDiff[getStationIndex(st->type)]; //TODO add the diff of  defaults waiting time
            if (sum2 != 0)
                sum = min(sum, sum2);
        }
    }

    return sum;
}

size_t StGraph::costOfBestRouteMixed(string startStation, string endStation, int num)
{
    if (num == 0)
        num = curr;
    int sum = 0, sum2;
    set<string> ava;
    ava = getSet(out, startStation, All);
    if (ava.find(endStation) == ava.end() || num == 1)
        return 0;
    auto allDests = getSet(out, startStation, All, 1);
    auto chck = allDests.find(endStation);
    auto st = findStation(startStation);
    if (chck != allDests.end())
    {
        auto p = st->findDestTranspTime(endStation);
        return st->type + p.first + transpDiff[getTranspIndex(p.second)] + stationDiff[getStationIndex(st->type)]; //TODO
    }
    pair<size_t, TransportType> p;
    for (auto &it : allDests)
    {
        p = st->findDestTranspTime(it);
        if (sum == 0)
        {
            sum = costOfBestRouteMixed(it, endStation, num - 1) + st->type + p.first + transpDiff[getTranspIndex(p.second)] + stationDiff[getStationIndex(st->type)]; //TODO
        }
        else
        {
            sum2 = costOfBestRouteMixed(it, endStation, num - 1) + st->type + p.first + transpDiff[getTranspIndex(p.second)] + stationDiff[getStationIndex(st->type)]; //TODO; //TODO
            if (sum2 != 0)
                sum = min(sum, sum2);
        }
    }
    return sum;
}
size_t StGraph::getTranspIndex(TransportType tt)
{
    switch (tt)
    {
    case Bus:
        return 0;
        break;
    case Tram:
        return 1;
        break;
    case Sprinter:
        return 2;
        break;
    case Rail:
        return 3;
        break;

    default:
        return -1;
        break;
    }
}

size_t StGraph::getStationIndex(StationType tt)
{
    switch (tt)
    {
    case Central:
        return 0;
        break;
    case Intercity:
        return 1;
        break;
    case Stad:
        return 2;
        break;

    default:
        return -1;
        break;
    }
}


StGraph::~StGraph()
{
}

std::ostream &operator<<(std::ostream &out, const Bounding &value)
{
    switch (value)
    {
    case in:
        return out << "in";
        break;
    case Bounding::out:
        return out << "out";
        break;
    }
    return out;
}