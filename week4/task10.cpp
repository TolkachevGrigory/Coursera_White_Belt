//
//  week4task10
//  Поменяйте реализацию конструктора класса Rational так, чтобы он выбрасывал исключение invalid_argument, если знаменатель равен нулю.
//  Кроме того, переделайте реализацию оператора деления для класса Rational так, чтобы он выбрасывал исключение domain_error, если делитель равен нулю.





#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;


class Rational {
public:
    Rational() {
        numerator_ = 0;
        denominator_ = 1;
    }

    Rational(long numerator, long denominator) {
            if(denominator != 0){
                numerator_ = abs(numerator);
                denominator_ = abs(denominator);
                if(numerator*denominator<0){
                    znak = true;
        }
                Ork(numerator_, denominator_);
            }else{
                throw invalid_argument("invalid_argument");
            }
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
    if(rhs.Numerator() != 0){
        return Rational(lhs.Numerator()*rhs.Denominator(), rhs.Numerator()*lhs.Denominator());
    }else{
        throw domain_error("domain_error");
    }
}

bool operator==(const Rational& lhs, const Rational& rhs){
    if(lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator()){
            return true;
    }else{
        return false;
    }
}

ostream& operator<<(ostream& stream, const Rational& rat){
    stream<<rat.Numerator()<<"/"<<rat.Denominator();
    return stream;
}

istream& operator>>(istream& stream, Rational& rat){
    int k,n;
    char s;
    if (stream >> k && stream>>s && stream >> n) {
        if(s == '/'){
            rat = {k ,n};
        }
    }
    
    return stream;
}

int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}
