//
//  week4task8.4
//   В этой части вам нужно реализовать операторы ввода и вывода для класса Rational. В результате у вас должен работать, например, такой код



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
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("");
        Rational r;
        bool correct = !(input >> r);
        if (!correct) {
            cout << "Read from empty stream works incorrectly" << endl;
            return 3;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 4;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 5;
        }
    }

    {
        istringstream input1("1*2"), input2("1/"), input3("/4");
        Rational r1, r2, r3;
        input1 >> r1;
        input2 >> r2;
        input3 >> r3;
        bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
        if (!correct) {
            cout << "Reading of incorrectly formatted rationals shouldn't change arguments: "
                 << r1 << " " << r2 << " " << r3 << endl;

            return 6;
        }
    }

    cout << "OK" << endl;
    return 0;
}
