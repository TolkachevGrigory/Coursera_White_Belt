//
//  week4task8.3
//   Аналогично предыдущей части, реализуйте операторы * и /. Например, следующий код должен быть валидным:



#include <iostream>
using namespace std;


class Rational {
public:
    Rational() {
        numerator_ = 0;
        denominator_ = 1;
    }

    Rational(long numerator, long denominator) {
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
    long numerator_;
    long denominator_;
    bool znak = false;
    void Ork(long& num, long& den){
        long numTmp = abs(num) ;
        long denTmp = abs(den);
        if(num == 0){
            den = 1;
        }else{
            long DOT;
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

Rational operator*(const Rational& lhs, const Rational& rhs){
    return Rational(lhs.Numerator()*rhs.Numerator(), rhs.Denominator()*lhs.Denominator());
}

Rational operator/(const Rational& lhs, const Rational& rhs){
    return Rational(lhs.Numerator()*rhs.Denominator(), rhs.Numerator()*lhs.Denominator());
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
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}
