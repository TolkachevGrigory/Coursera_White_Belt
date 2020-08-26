

#include <iostream>
#include <map>
#include <string>
#include <set>
#include <stdexcept>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;



class Date {
public:
    Date(int year,int month, int day){
        Year = year;
        if(month > 12 || month<1 ){
            throw invalid_argument("Month value is invalid: " + to_string(month));
        }
        Month = month;
        if(day<1 || day>31){
            throw invalid_argument("Day value is invalid: " + to_string(day));
        }
        Day = day;
    }
    
    int GetYear() const{
        return Year;
    }
    int GetMonth() const{
        return Month;
    }
    int GetDay() const{
        return Day;
    }
    
private:
    int Year = 0;
    int Month = 0;
    int Day;
};

bool operator<(const Date& lhs, const Date& rhs){
    if(lhs.GetYear() != rhs.GetYear()){
        return lhs.GetYear() < rhs.GetYear();
    }else{
        if(lhs.GetMonth() != rhs.GetMonth()){
            return lhs.GetMonth() < rhs.GetMonth();
        }else{
            if(lhs.GetDay() != rhs.GetDay()){
                return lhs.GetDay() < rhs.GetDay();
            }else{
                return false;
            }
        }
    }
};

ostream& operator<<(ostream& stream, const Date& date) {
  stream << setw(4) << setfill('0') << date.GetYear() <<
      "-" << setw(2) << setfill('0') << date.GetMonth() <<
      "-" << setw(2) << setfill('0') << date.GetDay();
  return stream;
}


class Database {
public:
    void AddEvent(const Date& date, const string& event){
        m[date].insert(event);
    }
    bool DeleteEvent(const Date& date, const string& event){
        if(m.count(date)>0 && m[date].count(event)>0){
            m[date].erase(event);
            return true;
        }else{
            return false;
        }
    }
    
    int  DeleteDate(const Date& date){
        int i = 0;
        if(m.count(date)>0){
            i = m[date].size();
            m.erase(date);
        }
        return i;
    }

    set<string> Find(const Date& date) {
        if(m.count(date)>0){
            return m[date];
        }
        return {};
    }
    
    void Print() const{
        for(const auto& init : m){
            for(const auto& event : init.second){
                cout<<init.first<<" "<<event<<endl;
            }
        }
    }
    
private:
    map<Date, set<string>> m;
};

Date ParseDate(const string& date) {
  istringstream date_stream(date);
  bool ok = true;

    int year = 0;
  ok = ok && (date_stream >> year);
  ok = ok && (date_stream.peek() == '-');
  date_stream.ignore(1);

    int month = 0;
  ok = ok && (date_stream >> month);
  ok = ok && (date_stream.peek() == '-');
  date_stream.ignore(1);

    int day = 0;
  ok = ok && (date_stream >> day);
  ok = ok && date_stream.eof();

  if (!ok) {
    throw invalid_argument("Wrong date format: " + date);
  }
  return Date(year, month, day);
}


int main() {
  Database db;
    
  string s;
  try{
      while (getline(cin, s)) {
          stringstream stream(s);
          string command;
          stream>>command;
          if(command == "Add"){
              string date_s, event;
              stream>>date_s>>event;
              const Date date = ParseDate(date_s);
              db.AddEvent(date, event);
              
          }else if(command == "Del"){
              string date_s, event;
              stream>>date_s;
              const Date date = ParseDate(date_s);
              if(!stream.eof()){
                  stream>>event;
              }
              if(event.empty()){
                  cout<<"Deleted "<<db.DeleteDate(date)<<" events"<<endl;
              }else{
                  if(db.DeleteEvent(date,event)){
                      cout<<"Deleted successfully"<<endl;
                  }else{
                      cout<<"Event not found"<<endl;
                  }
              }
          }else if(command == "Find"){
              string date_s;
              stream>>date_s;
              set<string> events = db.Find(ParseDate(date_s));
              for(const auto& event: events){
                  cout<<event<<endl;
              }
          }else if(command == "Print"){
              db.Print();
          }else if(!command.empty()){
              throw invalid_argument("Unknown command: " + command);
          }
      }
}catch (const invalid_argument& e) {
  cout << e.what() << endl;
}

  return 0;
}

