//
//  week2task5
//
//  Created by Григорий Толкачев on 01.08.2020.
//  Copyright © 2020 Григорий Толкачев. All rights reserved.
//  Напишите функцию MoveStrings, которая принимает два вектора строк,
//  source и destination, и дописывает все строки из первого вектора в конец второго.
//  После выполнения функции вектор source должен оказаться пустым.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

void MoveStrings(vector<string>& source,vector<string>& destination){
    for(auto i: source){
        destination.push_back(i);
    }
    source.clear();
}
int main(){
    vector<string> source = {"dq","qwd","dq"};
    vector<string> destination = {"d","q"};
    MoveStrings(source,destination);
        for (auto i:destination){
            cout<<i<<" ";
        }
    cout<<endl;
        for (auto i:source){
            cout<<i<<" ";
    }
    cout<<endl;
    return 0;
    }
    
