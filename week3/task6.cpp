//
//  week3task6 
//  Реализуйте класс ReversibleString, хранящий строку и поддерживающий методы Reverse для переворота строки и ToString для получения строки.
#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>
using namespace std;


class ReversibleString{
    public:
    ReversibleString(const string& word = ""){
        
        word_name = word;
    }
    void  Reverse(){
        reverse(word_name.begin(), word_name.end());
    }
    
    string ToString() const{
        return word_name;
    }
    
    private:
    string word_name;

};

int main() {
  ReversibleString s("live");
  s.Reverse();
  cout << s.ToString() << endl;
  
  s.Reverse();
  const ReversibleString& s_ref = s;
  string tmp = s_ref.ToString();
  cout << tmp << endl;
  
  ReversibleString empty;
 cout << '"' << empty.ToString() << '"' << endl;
  
  return 0;
}
