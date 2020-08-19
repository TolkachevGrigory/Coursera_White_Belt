//
//  week4task5

//  В файле input.txt записаны вещественные числа, по одному на строчку.
//  На стандартный вывод напечатайте эти числа в том же порядке, по одному на строке, но сделайте так,
//  чтобы у каждого из них было ровно три знака после десятичной точки.



#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
int main(){
    ifstream input("input.txt");
    double n;
    cout<< setprecision(3)<<fixed;
    if(input.is_open()){
        while(input){
            input>>n;
            if(input){
                cout<<n<<endl;
            }
        }
    }
    
    return 0;
}
