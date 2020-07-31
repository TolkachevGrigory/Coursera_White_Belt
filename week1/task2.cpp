//
//  week2task2
//
//  Created by Григорий Толкачев on 33.07.2020.
//  Copyright © 2020 Григорий Толкачев. All rights reserved.
//  Напишите функцию, которая
//  называется IsPalindrom
//  возвращает bool
//  принимает параметр типа string и возвращает, является ли переданная строка палиндромом
//  Палиндром - это слово или фраза, которые одинаково читаются слева направо и справа налево.
//  Пустая строка является палиндромом.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
bool IsPalindrom(string x){
    vector<char> xVector;
    int vectorsize;
    int k = 0;
    bool var;
    for (auto i: x){
        xVector.push_back(i);
    }
    vectorsize = xVector.size();
    if(xVector.size()==1){
        return true;
    }
    else if(vectorsize%2==0 && vectorsize>1){
        for(int i = 0; i<vectorsize/2; i++){
            if(xVector[i]==xVector[vectorsize-1-i]){
                k+=1;
            }
        }
        if(k==vectorsize/2){
            var =  true;
        }
        else{
            var =  false;
        }
    }
    else if(vectorsize%2!=0 && vectorsize>1){
        for(int i = 0; i<(vectorsize-1)/2; i++){
            if(xVector[i]==xVector[vectorsize-1-i]){
                k+=1;
            }
        }
        if(k==(vectorsize-1)/2){
            var = true;
        }
        else{
            var = false;
        }
    }
    return var;
}

int main(){
    string x;
    cin>>x;
    cout<<IsPalindrom(x)<<endl;
    return 0;
}
