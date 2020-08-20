//
//  week4task11
//  Вам надо написать программу, которая считывает из стандартного ввода одну строку в формате ДРОБЬ_1 операция ДРОБЬ_2. ДРОБЬ_1 и ДРОБЬ_2 имеют формат X/Y, где X — целое,
//  а Y — целое неотрицательное число. операция — это один из символов '+', '-', '*', '/'.

//  Если ДРОБЬ_1 или ДРОБЬ_2 является некорректной обыкновенной дробью, ваша программа должна вывести в стандартный вывод сообщение "Invalid argument".
//  Если считанная операция — это деление на ноль, выведите в стандартный вывод сообщение "Division by zero".

//   В противном случае выведите результат операции.


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
                throw runtime_error("Invalid argument");
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
        throw runtime_error("Division by zero");
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



Rational Calculate(const string& s ){
    stringstream stream(s);
    Rational rat, r1, r2;
    
    long n1, d1;
    long n2, d2;
    char z;
    stream>>n1;
    stream.ignore(1);
    stream>>d1;
    stream>>z;
    stream>>n2;
    stream.ignore(1);
    stream>>d2;
    r1 = {n1,d1};
    r2 = {n2,d2};
    if(z == '+'){
        rat = r1+r2;
    }else if(z == '-'){
        rat = r1-r2;
    }else if(z=='*'){
        rat = r1*r2;
    }else if(z == '/'){
        rat = r1 / r2;
    }
    return rat;
}

int main(){
    string s1,s2,s3;
    Rational rat;
    try{
        cin>>s1>>s2>>s3;
        string s = s1+s2+s3;
        rat = Calculate(s);
        cout<<rat.Numerator()<<"/"<<rat.Denominator()<<endl;
        
    }catch(runtime_error& ex){
        cout<<ex.what()<<endl;;
    }
        
    
    return 0;
}
