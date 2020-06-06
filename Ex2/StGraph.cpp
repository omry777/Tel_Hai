#include "StGraph.h"

StGraph::StGraph(string fileName)
{
    graph = vector<Station *>();
    curr = 0;

    load(fileName);

}
StGraph::StGraph(){
    this->graph = vector<Station *>(1000);
    this->curr = 0;
}


void StGraph::print(){

}

bool StGraph::load(string fileName){ //throws FILE exception
    ifstream file(fileName);
    
    if(false){ //TODO check if opened
        cerr << "Could not open file" << endl;
        return false;
    }
    
    TransportType type;
    // cout << "File opened" << endl;
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
    getline(file,startSt, '\t');
    getline(file,endSt,'\t');
    getline(file,sTime,'\n');
    time = stoi(sTime);
    // cout << startSt << endSt << time << endl;
    // while (file >> startSt >> endSt >> time){
        if((st = find(startSt)) != nullptr){
            if(( j = st->findDest(endSt, type)) != -1){ // Check if it this destination is already exists. if doesn't returns -1.
                int time2 = st->dests.at(j).second.second;
                if (time < time2)
                    st->dests.at(j).second.second = time;
            }
            else
            {
                st2 = find(endSt);
                if (st2 == nullptr){
                    st2 = new Station(endSt, type);
                    graph[curr++] = st2;
                }
                pair<Station*, int> temp(st2,time);
                st->addDest(type,temp);
                // st->dests.find(type)->second.insert(pair<Station *, int>(st2, time));  
                // vector<pair<TransportType,vector<pair<Station*,int>>>>::iterator it = std::find(st->dests.begin(), st->dests.end(), type);

            }
        }
        else
        {
            st = new Station(startSt, type);
            graph[curr++] = st;

            st2 = find(endSt);
            if (st2 == nullptr){
                // cout << "new Station" << endl;
                st2 = new Station(endSt, type);
                graph[curr++] = st2;
            }
            pair<Station*, int> temp (st2, time);
            st->addDest(type, temp);
	     
            
        }
    }    

    // }

    return true;
}

Station *StGraph::find(string startSt){
    for (size_t i=0 ; i < curr; i++){
        if (graph.at(i)->name.compare(startSt) == 0)
            return graph.at(i);
    }
    return nullptr;
}

void StGraph::printEverything(){
    for (size_t i = 0; i < curr; i++)
    {
        graph[i]->printStation();
    }
    
}

StGraph::~StGraph()
{
}
