//
//  week4task9
//  Напишите функцию
//  В случае, если строка left не равна строке right, функция должна выбрасывать исключение runtime_error с содержанием "<l> != <r>", где <l> и <r>
//  - строки, которые хранятся в переменных left и right соответственно. Обратите внимание, что вокруг знака неравенства в строке,
//  которая помещается в исключение, должно быть ровно по одному пробелу.
//  Если left == right, функция должна корректно завершаться.


#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <vector>
#include <map>
using namespace std;

void EnsureEqual(const string& left, const string& right){
    if(left != right){
        throw runtime_error(left + " != "+ right);
    }
}

int main() {
  try {
    EnsureEqual("C++ White", "C++ White");
    EnsureEqual("C++ White", "C++ Yellow");
  } catch (runtime_error& e) {
    cout << e.what() << endl;
  }
  return 0;
}
