//
//  week2task14//
//  В этой задаче вам нужно присваивать номера автобусным маршрутам.
//  А именно, для каждого маршрута, заданного набором названий остановок, нужно либо выдать новый номер
//  (первому маршруту — 1, второму — 2 и т. д.), либо вернуть номер существующего маршрута, которому соответствует такой набор остановок.
//  Наборы остановок, полученные друг из друга перестановкой остановок, считаются различными (см. пример).
#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <vector>
using namespace std;

void NewBus(map<vector<string>, int>& m, vector<string> stops){
    if(m.count(stops) == 0){
        m[stops] = m.size() + 1;
        cout<<"New bus "<<m.size()<<endl;
    }else{
        cout<<"Already exists for "<<m[stops]<<endl;
    }
}


int main(){
    map<vector<string>, int> m;
    int q;
    cin>>q;
    for(int i = 0; i<q; ++i){
        int stop_count;
        vector<string> stops;
        cin>>stop_count;
        for(int k = 0; k<stop_count; ++k){
            string stop;
            cin>>stop;
            stops.push_back(stop);
        }
        NewBus(m, stops);
    }
    return 0;
}
