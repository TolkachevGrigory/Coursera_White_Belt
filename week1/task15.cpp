//
//  week2task15
// Дан набор строк. Найдите количество уникальных строк в этом наборе.


#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <vector>
#include <set>
using namespace std;
int main(){
    int N;
    cin>>N;
    set<string> unic;
    for (int i = 0; i<N; ++i){
        string word;
        cin>>word;
        unic.insert(word);
    }
    cout<<unic.size()<<endl;
    return 0;
}
