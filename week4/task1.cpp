//
//  week4task1
//  Дана структура LectureTitle:
//  Допишите конструктор и структуры Specialization, Course, Week так, чтобы объект LectureTitle можно было создать с помощью кода
//  LectureTitle title(
//      Specialization("C++"),
//       Course("White belt"),
//       Week("4th")
//   );
//
//

#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>
using namespace std;

struct Specialization{
    string value;
    explicit Specialization(string new_value){
        value = new_value;
    }
};

struct Course{
    string value;
    explicit Course(string new_value){
        value = new_value;
    }
};

struct Week{
    string value;
    explicit Week(string new_value){
        value = new_value;
    }
};

struct LectureTitle {
    string specialization;
    string course;
    string week;
    LectureTitle(Specialization new_spec, Course new_course,Week new_week){
        specialization = new_spec.value;
        course  = new_course.value;
        week = new_week.value;
    }
    

};

void Print (const LectureTitle& lecture){
    cout<<lecture.specialization<<" "<<lecture.course<<" "<<lecture.week<<endl     ;
}


