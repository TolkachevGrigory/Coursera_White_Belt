//
//  week4task8.1
//  В первой части Вам надо реализовать класс Rational, который представляет собой рациональное число
//  вида p/q, где p — целое, а q — натуральное и диапазоны возможных значений p, q таковы, что могут быть представлены типом int.
//  При этом, класс Rational должен иметь следующий интерфейс:

#include <iostream>
using namespace std;

class Rational {
public:
    Rational() {
        numerator_ = 0;
        denominator_ = 1;
    }

    Rational(int numerator, int denominator) {
        numerator_ = abs(numerator);
        denominator_ = abs(denominator);
        if(numerator*denominator<0){
            znak = true;
        }
        Ork(numerator_, denominator_);
    }
    

    int Numerator() const {
        if(znak == true){
            return -numerator_;
        }
        return numerator_;
    }

    int Denominator() const {
        return denominator_;
    }

private:
    int numerator_;
    int denominator_;
    bool znak = false;
    void Ork(int& num, int& den){
        int numTmp = num ;
        int denTmp = den;
        if(num == 0){
            den = 1;
        }else{
            int DOT;
            while(numTmp > 0 && denTmp > 0){
                if (numTmp > denTmp) {
                    numTmp %= denTmp;
                } else {
                    denTmp %= numTmp;
                }
                }
            DOT =numTmp + denTmp;
            num = num/DOT;
            den= den/DOT;
        }
    }
};
int main() {
    {
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
            cout << "Rational(3, 10) != 3/10" << endl;
            return 1;
        }
    }

    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "Rational(8, 12) != 2/3" << endl;
            return 2;
        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(-4, 6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(4, -6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            cout << "Rational(0, 15) != 0/1" << endl;
            return 4;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            cout << "Rational() != 0/1" << endl;
            return 5;
        }
    }

    cout << "OK" << endl;
    return 0;
}
