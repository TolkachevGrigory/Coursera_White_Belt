//
//  week2task8
//
//  Даны значения температуры, наблюдавшиеся в течение N подряд идущих дней.
//  Найдите номера дней (в нумерации с нуля) со значением температуры выше среднего
//  арифметического за все N дней.
//  Гарантируется, что среднее арифметическое значений температуры является целым числом.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

vector<int> temperature(vector<int> vec){
    int sum = 0;
    vector<int> vecout;
    for(int i: vec){
        sum+=i;
    }
    double average = sum/vec.size();
    for(int i = 0; i<vec.size(); ++i){
        if(vec[i]>average){
            vecout.push_back(i);
        }
    }
    return vecout;
}

int main(){
    int n;
    cin>>n;
    vector<int> vecinput(n);
    vector<int> vecoutput;
    for(int& i: vecinput){
        cin>>i;
    }
    
    vecoutput = temperature(vecinput);
    cout<<vecoutput.size()<<endl;
    for(int i: vecoutput){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
