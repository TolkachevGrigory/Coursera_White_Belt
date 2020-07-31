//
//  week2task1
//
//  Created by Григорий Толкачев on 33.07.2020.
//  Copyright © 2020 Григорий Толкачев. All rights reserved.
//  Напишите функцию, которая
//  называется Factorial
//  возвращает int
//  принимает int и возвращает факториал своего аргумента.
//  Гарантируется, что аргумент функции по модулю не превышает 10.
//  Для отрицательных аргументов функция должна возвращать 1.

#include <iostream>
#include <math.h>
using namespace std;
int Factorial(int x){
    int fact = 1;
    if ( x< 0){
        return 1;
    }
    else{
        for(int i=1; i<=x; i++){
            fact*=i;
        }
    }
    return fact;
}

int main() {
    int x;
    cin>>x;
    cout<<Factorial(x)<<endl;
    return 0;
}

