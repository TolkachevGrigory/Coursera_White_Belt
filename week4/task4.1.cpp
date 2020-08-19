//
//  week4task4.1

//  Часть 1
//  Ваша программа должна считать содержимое файла input.txt и напечатать его на экран без изменений.
//  Гарантируется, что содержимое файла input.txt заканчивается переводом строки.


#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main(){
    ifstream input("input.txt");
    string line;
    if(input.is_open()){
        while(getline(input, line)){
            cout<<line<<endl;
        }
    }
    
    return 0;
}
