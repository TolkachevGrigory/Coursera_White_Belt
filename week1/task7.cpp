//
//  week2task7
//
//  Created by Григорий Толкачев on 01.08.2020.
//  Copyright © 2020 Григорий Толкачев. All rights reserved.
//  Реализуйте функцию vector<int> Reversed(const vector<int>& v), возвращающую копию вектора v,
//  в которой числа переставлены в обратном порядке.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

vector<int> Reversed(const vector<int>& v){
    vector<int> w = v;
    size_t k = v.size();
    
    for(int i= 0; i<k; i++ ){
        w[k-1-i] = v[i];
    }
    return w;
}
int main(){
    vector<int> v = {1,2,3,4};
    Reversed(v);
    for(auto i:v){
        cout<<i<<" ";
    }
    return 0;
}
