//
//  week3task7

//  Дополните класс Person из задачи «Имена и фамилии — 2» конструктором, позволяющим задать имя и фамилию человека при рождении,
//  а также сам год рождения. Класс не должен иметь конструктора по умолчанию.
//  При получении на вход года, который меньше года рождения:
//  методы GetFullName и GetFullNameWithHistory должны отдавать "No person";
//  методы ChangeFirstName и ChangeLastName должны игнорировать запрос.
//  Кроме того, необходимо объявить константными все методы, которые по сути ими являются.

#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>
using namespace std;




class Person {
public:
    
  Person(const string& first_name, const string& last_name, int year ){
      first_names[year] = first_name;
      last_names[year] = last_name;
  }
    
  void ChangeFirstName(int year, const string& first_name) {
      first_names[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
      last_names[year] = last_name;
    
  }
  string GetFullName(const int year) const {
      string first_name = HelpMe(first_names, year);
      string last_name = HelpMe(last_names,year);
      if(last_name.empty() && first_name.empty()){
          return "No person";
      }else if(first_name.empty()){
          return  last_name + " with unknown first name";
      }else if(last_name.empty()){
          return first_name + " with unknown last name";
      }else{
          return first_name +" "+last_name;
      }
      
  }
      string GetFullNameWithHistory(int year) const{
          string first_name = HelpMe(first_names,year);
          string last_name = HelpMe(last_names, year);
          string story1 = GetHistory(first_names,year);
          string story2 = GetHistory(last_names,year);
          
          
          if(last_name.empty() && first_name.empty()){
              return "No person";
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
    
    
    string HelpMe(map<int,string> m, int year) const{
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
    string GetHistory(const map<int,string>& m, const int& year) const{
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
  Person person("Polina", "Sergeeva", 1960);
  for (int year : {1959, 1960}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1965, "Appolinaria");
  person.ChangeLastName(1967, "Ivanova");
  for (int year : {1965, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  return 0;
}
