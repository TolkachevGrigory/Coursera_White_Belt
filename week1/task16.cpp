//
//  week2task16
//  В этой задаче вам нужно присваивать номера автобусным маршрутам.
//  А именно, для каждого маршрута, заданного множеством названий остановок, нужно либо выдать новый номер
//  (первому маршруту — 1, второму — 2 и т. д.), либо вернуть номер существующего маршрута,
//  которому соответствует такое множество остановок.
//  В отличие от задачи «Автобусные остановки — 2», наборы остановок, которые можно получить
//  друг из друга перестановкой элементов или добавлением/удалением повторяющихся, следует считать одинаковыми.
#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <vector>
#include <set>
using namespace std;

void NewBus(map<set<string>, int>& m, set<string> stops){
    if(m.count(stops) == 0){
        m[stops] = m.size() + 1;
        cout<<"New bus "<<m.size()<<endl;
    }else{
        cout<<"Already exists for "<<m[stops]<<endl;
    }
}


int main(){
    map<set<string>, int> m;
    int q;
    cin>>q;
    for(int i = 0; i<q; ++i){
        int stop_count;
        set<string> stops;
        cin>>stop_count;
        for(int k = 0; k<stop_count; ++k){
            string stop;
            cin>>stop;
            stops.insert(stop);
        }
        NewBus(m, stops);
    }
    return 0;
}
