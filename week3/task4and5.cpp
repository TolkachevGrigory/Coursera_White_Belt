//
//  week3task5 and week3task4
//  Дополните класс из предыдущей задачи «Имена и фамилии — 1» методом GetFullNameWithHistory:
//  В отличие от метода GetFullName, метод GetFullNameWithHistory должен вернуть не только последние
//  имя и фамилию к концу данного года, но ещё и все предыдущие имена и фамилии в обратном хронологическом порядке.
//  Если текущие факты говорят о том, что человек два раза подряд изменил фамилию или имя на одно и то же, второе
//  изменение при формировании истории нужно игнорировать.
#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>
using namespace std;



string FindName(int year,map<int,string>& m ){
    string name;
    for(const auto& unit: m){
        if(unit.first<=year){
            name = unit.second;
        }else{
            break;
        }
    }
    return name;
}


class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
      first_names[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
      last_names[year] = last_name;
    
  }
  string GetFullName(int year) {
      string first_name = HelpMe(first_names, year);
      string last_name = HelpMe(last_names,year);
      if(last_name.empty() && first_name.empty()){
          return "Incognito";
      }else if(first_name.empty()){
          return  last_name + " with unknown first name";
      }else if(last_name.empty()){
          return first_name + " with unknown last name";
      }else{
          return first_name +" "+last_name;
      }
      
  }
      string GetFullNameWithHistory(int year) {
          string first_name = HelpMe(first_names,year);
          string last_name = HelpMe(last_names, year);
          string story1 = GetHistory(first_names,year);
          string story2 = GetHistory(last_names,year);
          
          
          if(last_name.empty() && first_name.empty()){
              return "Incognito";
          }else if(first_name.empty()){
              if(story2.empty()){
                  return  last_name + " with unknown first name";
              }else{
                  return last_name +" "+ story2+" with unknown first name";
              }
          }else if(last_name.empty()){
              if(story1.empty()){
                  return first_name + " with unknown last name";
              }else{
                  return first_name+" "+ story1 + " with unknown last name";
              }
          }else{
              if( story1.empty() && story2.empty() ){
                  return first_name +" "+last_name;
              }else if(story2.empty()){
                  return first_name +" "+story1+" "+last_name;
              }else if(story1.empty()){
                  return first_name +" "+last_name+" "+story2;
              }else{
                  return first_name +" "+story1+" "+last_name+" "+story2;
              }
          
       }
      }
      
    void Print(){
        for(const auto& i:first_names){
            cout<<i.first<<" "<<i.second<<endl;
        }
    }
  
   
private:
    map<int, string> first_names;
    map<int, string> last_names;
    
    
    string HelpMe(map<int,string> m, int year){
        string outname;
        if(m.count(year) ==0){
            for(auto i = m.begin(); i!=m.end(); ++i){
                if(i->first <= year){
                    outname =i->second;
                }
            }
        }else{
            outname = m[year];
        }
        
        return outname;
    }
    string GetHistory(const map<int,string>& m, const int& year){
        vector<string> history;
        string story;
        string TempString;
        for(const auto& item: m ){
            if(item.first>year)
                break;
            if(TempString != item.second){
                history.push_back(item.second);
                TempString = item.second;
            }
        }
        if(history.size()>0){
            history.pop_back();
        }
        reverse(history.begin(), history.end());
        
        if(history.size() == 1){
            story = "("+history[0]+")";
        }else if(history.size() > 1){
            story = "("+history[0];
            for(int i = 1; i<history.size(); ++i){
                story +=", " + history[i];
                if(i == history.size()-1){
                    story +=")";
                }
            }
        }
        return story;
    }
    
};

int main() {
  Person person;
  
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1990, "Polina");
  person.ChangeLastName(1990, "Volkova-Sergeeva");
  cout << person.GetFullNameWithHistory(1990) << endl;
  
  person.ChangeFirstName(1966, "Pauline");
  cout << person.GetFullNameWithHistory(1966) << endl;
  
  person.ChangeLastName(1960, "Sergeeva");
  for (int year : {1960, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeLastName(1961, "Ivanova");
  cout << person.GetFullNameWithHistory(1967) << endl;
  
  return 0;
}
