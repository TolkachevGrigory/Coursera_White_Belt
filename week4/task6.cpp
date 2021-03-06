//
//  week4task6

//  В первой строке файла input.txt записаны два числа N и M. Далее в файле находится таблица из N строк и M столбцов,
//  представленная в формате CSV (comma-separated values). Такой формат часто используется для текстового представления таблиц с данными:
//  в файле несколько строк, значения из разных ячеек внутри строки отделены друг от друга запятыми.
//  Ваша задача — вывести данные на экран в виде таблицы. Формат таблицы:
//  1) размер ячейки равен 10,
//  2) соседние ячейки отделены друг от друга пробелом,

//  3) последняя ячейка в строке НЕ оканчивается пробелом,

//  4) последняя строка НЕ оканчивается символом перевода строки. Гарантируется, что в таблице будет ровно N строк и M столбцов,
//  значение каждой из ячеек — целое число. Пример ввода



#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
int main() {
    ifstream input("input.txt");

    int row = 0;
    int column = 0;
    if (input.is_open()) {
        input >> row;
        input.ignore(1);
        input >> column;
        for (int i=0; i < row; ++i) {
            for (int j=0; j <= (column*2-1); ++j) {
                int n;
                cout << setw(10) << fixed;
                if (j % 2 == 0 && j < (column*2-2)) {
                    input >> n;
                    cout << n<<" ";
                } else if (j % 2 == 0 && j == (column*2-2)) {
                    input >> n;
                    cout << n;
                } else {
                    input.ignore(1);
                }
            }
            cout << endl;
        }
    }

    return 0;
}

