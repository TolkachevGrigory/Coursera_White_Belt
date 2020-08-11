//
//  week3task2
//  В стандартном потоке дана одна строка, состоящая из числа N и следующих за ним N строк S.
//  Между собой число и строки разделены пробелом.
//  Отсортируйте строки S в лексикографическом порядке по возрастанию, игнорируя регистр букв, и выведите их в стандартный поток вывода.

#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>

using namespace std;

int main(){
    
    
    int N;
    cin>>N;
    vector<string> vec;
    for(int i = 0; i<N; ++i){
        string elem;
        cin>>elem;
        vec.push_back(elem);
    }
    sort(begin(vec),end(vec), [](string  a,string b){
        for(auto& i:a){
            i = tolower(i);
        }
        for(auto& i:b){
            i = tolower(i);
        }
        return a < b ;
    });
    for(auto i: vec){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
