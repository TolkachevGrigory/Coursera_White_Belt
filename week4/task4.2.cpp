//
//  week4task4.2

//  Снова считайте все содержимое файла input.txt, но на этот раз выведите его в файл output.txt .
//  Точно так же гарантируется, что содержимое файла input.txt заканчивается переводом строки.

#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main(){
    ifstream input("input.txt");
    ofstream output("output.txt");
    string line;
    if(input.is_open()){
        while(getline(input, line)){
            output<<line<<endl;
        }
    }
    
    return 0;
}
