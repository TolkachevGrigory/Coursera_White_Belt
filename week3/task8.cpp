//
//  week3task8

//  Определите тип Incognizable, для которого следующий код будет корректен:

#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>
using namespace std;



class Incognizable{
    public:
        Incognizable(const int& number1 = 0,const int& number2 = 0){
            number1_ = number1;
            number2_ = number2;
        }
    private:
    int number1_ = 0;
    int number2_ = 0;
};

int main() {
  Incognizable a;
  Incognizable b = {};
  Incognizable c = {0};
  Incognizable d = {0, 1};
  return 0;
}
