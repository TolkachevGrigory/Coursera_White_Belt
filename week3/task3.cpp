//
//  week3task3
// Реализуйте класс, поддерживающий набор строк в отсортированном порядке. Класс должен содержать два публичных метода:
#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>

using namespace std;

class SortedStrings {
public:
  void AddString(const string& s) {
      vec.push_back(s);
  }
  vector<string> GetSortedStrings() {
      sort(begin(vec), end(vec));
      return vec;
  }
private:
    vector<string> vec;
};

void PrintSortedStrings(SortedStrings& strings) {
  for (const string& s : strings.GetSortedStrings()) {
    cout << s << " ";
  }
  cout << endl;
}

int main(){
    SortedStrings strings;
     strings.AddString("first");
     strings.AddString("third");
     strings.AddString("second");
     PrintSortedStrings(strings);
     strings.AddString("second");
     PrintSortedStrings(strings);
    return 0;
}
