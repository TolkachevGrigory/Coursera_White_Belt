//
//  week4task8.2
//   Реализуйте для класса Rational операторы ==, + и - так, чтобы операции с дробями можно было записывать естественным образом.
//  Например, следующий код должен быть валидным:



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
        int numTmp = abs(num) ;
        int denTmp = abs(den);
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

Rational operator+(const Rational& lhs, const Rational& rhs){
    return Rational(lhs.Numerator()*rhs.Denominator() + rhs.Numerator()*lhs.Denominator(), rhs.Denominator()*lhs.Denominator());
}
Rational operator-(const Rational& lhs, const Rational& rhs){
    return Rational(lhs.Numerator()*rhs.Denominator() - rhs.Numerator()*lhs.Denominator(), rhs.Denominator()*lhs.Denominator());
}


bool operator==(const Rational& lhs, const Rational& rhs){
    if(lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator()){
            return true;
    }else{
        return false;
    }
}
int main() {
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
