//
//  week2task9
//
//  Люди стоят в очереди, но никогда не уходят из её начала, зато могут приходить в конец и уходить оттуда.
//  Более того, иногда некоторые люди могут прекращать и начинать беспокоиться из-за того, что очередь не продвигается.
//  Реализуйте обработку следующих операций над очередью:
//  WORRY i: пометить i-го человека с начала очереди (в нумерации с 0) как беспокоящегося;
//  QUIET i: пометить i-го человека как успокоившегося;
//  COME k: добавить k спокойных человек в конец очереди;
//  COME -k: убрать k человек из конца очереди;
//  WORRY_COUNT: узнать количество беспокоящихся людей в очереди.
//  Изначально очередь пуста.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

void Come(vector<bool>& people,int n){
    if(n>0){
        for(int i = 0; i<n; ++i){
            people.push_back(false);
        }
    }
    else if(n<0){
        for(int i = 0; i<-n; ++i){
        people.pop_back();
        }
    }
}

void Worry(vector<bool>& people,int n){
    people[n] = true;
}
    
void Quiet(vector<bool>& people,int n){
    people[n] = false;
}
    
void Worry_count(vector<bool>& people){
    int wp = 0;
    for(auto i: people){
        if(i == 1){
            wp+=1;
        }
    }
    cout<<wp<<endl;
}
void PrinVector(vector<bool> vector){
    for(auto i: vector){
        cout<<i<<" ";
    }
}
int main(){
    int Q;
    cin>>Q;
    vector<bool> people;
    for(int i = 0; i<Q; i++){
        string s;
        int num;
        cin>>s;
        if(s == "WORRY_COUNT"){
            Worry_count(people);
        }
        else{
            cin>>num;
            if(s == "COME"){
                Come(people,num);
            }
            else if(s == "WORRY"){
                Worry(people, num);
            }
            else if(s == "QUIET"){
                Quiet(people, num);
            }
        }
    }
    return 0;
}
