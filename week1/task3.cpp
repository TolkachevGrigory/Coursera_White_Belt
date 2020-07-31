//
//  week2task2
//
//  Created by Григорий Толкачев on 31.07.2020.
//  Copyright © 2020 Григорий Толкачев. All rights reserved.
//  Напишите функцию, которая
//  называется PalindromFilter
//  возвращает vector<string>
//  принимает vector<string> words и int minLength и возвращает все строки из вектора words,
//  которые являются палиндромами и имеют длину не меньше minLength
//  Входной вектор содержит не более 100 строк, длина каждой строки не больше 100 символов.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

bool IsPalindrom(string s) {
    for (int i = 0; i < s.size() / 2; ++i) {
        if (s[i] != s[s.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

vector<string> PalindromFilter(vector<string> words, int minLength){
    vector<string> result;
    for(auto i : words){
        if(IsPalindrom(i)==1 and i.size()>= minLength ){
            result.push_back(i);
        }
    }
    
    return result;
}
int main(void){
   vector<string> words = PalindromFilter({"abacaba", "aba"}, 5);
   for (auto word : words) {
       cout << word << " ";
   }
   cout << endl;
   words = PalindromFilter({"abacaba", "aba"}, 2);
   for (auto word : words) {
       cout << word << " ";
   }
   cout << endl;
   words = PalindromFilter({"weew", "bro", "code"}, 4);
   for (auto word : words) {
       cout << word << " ";
   }
   cout << endl;

    return 0;
}
