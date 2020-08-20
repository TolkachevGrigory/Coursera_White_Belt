//
//  week4task7

//  Определите структуру «Студент» со следующими полями: имя, фамилия, день, месяц и год рождения.
//  Создайте вектор из таких структур, заполните его из входных данных и затем по запросам
//  выведите нужные поля.


#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;
struct Student{
    string first_name;
    string second_name;
    string date;
};
int main() {
    int N;
    cin>>N;
    vector<Student> students(N);
    for(int i = 0; i<N; ++i){
        string d;
        string m;
        string y;
        cin>>students[i].first_name>>students[i].second_name>>d>>m>>y;
        students[i].date = d + "."+ m +"."+y;
    }
    int M;
    cin>>M;
    for(int i = 0; i<M; ++i){
        string s;
        cin>>s;
        int k;
        cin>>k;
        
        if(s == "name" && k>0 && k <= N ){
            
            cout<<students[k-1].first_name<<" "<<students[k-1].second_name<<endl;
        }else if( s == "date" && k>0 && k <= N){
            cout<<students[k-1].date<<endl;
        }else{
            cout<<"bad request"<<endl;
        }
    }

    return 0;
}

