//
//  week3task1
//  В стандартном потоке дана одна строка, состоящая из N + 1 целых чисел.
//  Первым числом идёт само число N. Далее следуют ещё N чисел, обозначим их за массив A. Между собой числа разделены пробелом.
//  Отсортируйте массив А по модулю и выведите его в стандартный поток.

#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int> vec;
    for(int i = 0; i<N; ++i){
        int elem;
        cin>>elem;
        vec.push_back(elem);
    }
    sort(begin(vec),end(vec), [](int& a,int& b){return abs(a)<abs(b);});
    for(auto i: vec){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
