//
//  week2task12
//
//  Реализуйте справочник столиц стран.
//  На вход программе поступают следующие запросы:
//  CHANGE_CAPITAL country new_capital — изменение столицы страны country на new_capital,
//  либо добавление такой страны с такой столицей, если раньше её не было.
//  RENAME old_country_name new_country_name — переименование страны из old_country_name в new_country_name.
//  ABOUT country — вывод столицы страны country.
//  DUMP — вывод столиц всех стран.
#include <iostream>
#include <string>
#include <math.h>
#include <map>
using namespace std;


void ChageCapital(map<string,string>& m, string country, string new_capital){
    if(m[country]==""){
        m[country] = new_capital;
        cout<<"Introduce new country "<<country<<" with capital "<<new_capital<<endl;
    }else if(m[country]==new_capital){
        cout<<"Country "<<country<<" hasn't changed its capital"<<endl;
    }else{
        cout<<"Country "<<country<<" has changed its capital from "<<m[country]<<" to "<<new_capital<<endl;
        m[country] = new_capital;
    }
}

void RenameCountry(map<string,string>& m, string old_country_name , string new_country_name){
    if(old_country_name == new_country_name || m.count(old_country_name) == 0 || m.count(new_country_name)>0){
        cout<<"Incorrect rename, skip"<<endl;
    }else{
        cout<<"Country "<<old_country_name<<" with capital "<<m[old_country_name]<<" has been renamed to "<<new_country_name<<endl;
        m[new_country_name] = m[old_country_name];
        m.erase(old_country_name);
    }
}

void About(map<string,string>& m, string& country){

    if(m.count(country) == 0){
        cout<<"Country "<<country<<" doesn't exist"<<endl;
    }else{
        cout<<"Country "<<country<<" has capital "<<m[country]<<endl;
    }
}

void Dump(map<string,string>& m){
    if(m.size() == 0){
        cout<<"There are no countries in the world"<<endl;
    }else{
        for(const auto& item:m){
            cout<<item.first<<"/"<<item.second<<" ";
        }
        cout<<endl;
    }
}



int main(){
    map<string,string> m;
    int q;
    cin>>q;
    for(int i = 0; i<q; ++i){
        string s;
        cin>>s;
        string country,new_capital, old_country_name, new_country_name;
        if(s == "CHANGE_CAPITAL"){
            cin>>country>>new_capital;
            ChageCapital(m,country,new_capital);
        }else if(s == "RENAME"){
            cin>>old_country_name>>new_country_name;
            RenameCountry(m, old_country_name, new_country_name);
        }else if(s == "ABOUT"){
            cin>>country;
            About(m, country);
        }else if( s == "DUMP"){
            Dump(m);
        }
    }
   
    
    return 0;
}
