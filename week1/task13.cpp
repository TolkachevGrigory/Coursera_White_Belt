//
//  week2task13//
//  Реализуйте систему хранения автобусных маршрутов. Вам нужно обрабатывать следующие запросы:
//  NEW_BUS bus stop_count stop1 stop2 ... — добавить маршрут автобуса с названием bus и stop_count остановками с названиями stop1, stop2, ...
//  BUSES_FOR_STOP stop — вывести названия всех маршрутов автобуса, проходящих через остановку stop.
//  STOPS_FOR_BUS bus — вывести названия всех остановок маршрута bus со списком автобусов, на которые можно пересесть на каждой из остановок.
//  ALL_BUSES — вывести список всех маршрутов с остановками.
#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <vector>
using namespace std;

void NewBus(map<string,vector<string>>& m, string bus, vector<string> stops){
     m.insert(pair<string, vector<string>>(bus, stops));
}

void BusesForStop(map<string,vector<string>>& m, string stop, vector<string> buses){
    vector<string> stops;
    for(auto bus: buses){
        for(auto i: m[bus]){
            if(stop == i){
                stops.push_back(bus);
            }
        }
    }
    if(stops.size() == 0){
        cout<<"No stop"<<endl;
    }else{
        for(auto i: stops){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}

void StopForBus(map<string,vector<string>>& m, string bus, vector<string> buss){
    if(m.count(bus)>0){
        map<string,vector<string>> stations;
        for(auto stop: m[bus]){
            vector<string> buses;
            for( auto unit: buss){
                if(unit != bus){
                    for(auto stop1: m[unit]){
                        if(stop1 == stop){
                            buses.push_back(unit);
                        }
                    }
                }
            }
            stations[stop] = buses;
        }
        
        for(auto stop: m[bus]){
            cout<<"Stop "<<stop<<": ";
            if(stations[stop].size() != 0 ){
                for(auto bus: stations[stop]){
                    cout<<bus<<" ";
                }
            }else{
                cout<<"no interchange";
            }
            cout<<endl;
        }
    }else{
        cout<<"No bus"<<endl;
    }
}

void AllBuses(map<string,vector<string>>& m){
    if(m.size()>0){
        for(const auto& bus: m){
            cout<<"Bus "<<bus.first<<": ";
            for(auto stop: bus.second){
                cout<<stop<<" ";
            }
            cout<<endl;
        }
    }else{
        cout<<"No buses"<<endl;
    }
}

int main(){
    map<string, vector<string>> m;
    vector<string> buses;
    int q;
    cin>>q;
    for(int i = 0; i<q; ++i){
        string s;
        cin>>s;
        if(s == "NEW_BUS"){
            string bus;
            int stop_count;
            vector<string> stops;
            cin>>bus;
            buses.push_back(bus);
            cin>>stop_count;
            for(int k = 0; k<stop_count; ++k){
                string stop;
                cin>>stop;
                stops.push_back(stop);
            }
            NewBus(m, bus, stops);
        }else if( s == "BUSES_FOR_STOP"){
            string stop;
            cin>>stop;
            BusesForStop(m, stop, buses);
        }else if(s == "STOPS_FOR_BUS"){
            string bus;
            cin>>bus;
            StopForBus(m, bus, buses);
        }else if(s == "ALL_BUSES" ){
            AllBuses(m);
        }
    }
    return 0;
}
