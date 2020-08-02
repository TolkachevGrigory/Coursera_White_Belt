//
//  week2task4
//
//  Created by Григорий Толкачев on 31.07.2020.
//  Copyright © 2020 Григорий Толкачев. All rights reserved.
//  Напишите функцию UpdateIfGreater, которая принимает два целочисленных аргумента:
//  first и second. Если first оказался больше second,
//  Ваша функция должна записывать в second значение параметра first.
//  При этом указанная функция не должна ничего возвращать,
//  а изменение параметра second должно быть видно на вызывающей стороне.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

void UpdateIfGreater(int first,int& second){
    if(first>second){
        second = first;
    }
}

int main(){
    int x,y;
    cin>>x>>y;
    UpdateIfGreater(5,y);
    cout<<x<<" "<<y<<endl;
    return 0;
}
