//
//  main.cpp
//  Chudnovsky's pi
//
//  Created by Simone Cimolato on 27/01/18.
//  Copyright © 2018 Simone Cimolato. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

typedef __int128 int128_t;

/*      UINT64_MAX 18446744073709551615ULL */
#define P10_UINT64 10000000000000000000ULL   /* 19 zeroes */
#define E10_UINT64 19

#define STRINGIZER(x)   # x
#define TO_STRING(x)    STRINGIZER(x)

std::ostream&
operator<<(std::ostream& dest, __int128_t value){
    std::ostream::sentry s(dest);
    if (s){
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[128];
        char* d = std::end(buffer);
        do{
            -- d;
            *d = "0123456789"[tmp % 10];
            tmp /= 10;
        } while (tmp != 0);
        if (value < 0) {
            -- d;
            *d = '-';
        }
        long len = std::end(buffer) - d;
        if (dest.rdbuf()->sputn(d, len) != len) {
            dest.setstate(std::ios_base::badbit);
        }
    }
    return dest;
}

int factorial(int n);
int i;
double num1 = 426880*sqrt(10005);
__int128_t num2 = factorial(6*i)*(545140134*i + 13591409);
__int128_t den1 = factorial(3*i) * pow(factorial(i), i);
__int128_t den2 = pow(-262537412640768000, i);


int main(int argc, const char * argv[]) {
    long double pi = 0;

    clock_t start = clock();
    
    for (i = 0; i <= 1000; i++) {
        pi += num2/(den1*den2); //too fucking big
    }
    pi = num1 / pi;
    
    clock_t end = clock();
    double time = (double) (end-start) / CLOCKS_PER_SEC;
    
    //cout.precision(101);
    cout<<pi<<endl<<endl;
    cout.precision(5);
    cout<<"Time taken: "<<time<<" seconds"<<endl;
    return 0;
}
int factorial(int n){
    return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}
