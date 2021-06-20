//
//  main.cpp
//  Primes
//
//  Created by Simone Cimolato on 31/03/17.
//  Copyright © 2017 Simone Cimolato. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

unsigned long primeCounter = 4;

int isPrime(unsigned long number);

int main(int argc, const char * argv[]) {
   
    //must be > 8
    unsigned long lastOne = 0;
    cout<<"Last number to check: "<<endl;           //problems if i don't put endl at the end
    
    cin>>lastOne;
    if (cin.fail() or lastOne < 9) {
        cout<<"Must be an integer greater than 8."<<endl;
        return 1;
    }
    clock_t start = clock();

    cout<<endl<<2<<", "<<3<<", "<<5<<", "<<7<<", ";

    /*
      k starts from 8 because in the isPrime function i check 
      if k is a multiple of 2,3,5,7 and if it is, then k is not prime, but 2,3,5,7 are actually primes, so if
      k was 2,3,5 or 7 then it wouldn't be counted as prime
     */
  
    for (int k = 9; k <= lastOne; k+=2){
        isPrime(k);
    }
    cout<<endl<<endl<<primeCounter<<" primes found"<<endl<<endl;
    clock_t end = clock();
    double time = (double) (end-start) / CLOCKS_PER_SEC;
    cout<<time<<" seconds."<<endl;
    return 0;
}

int isPrime(unsigned long number){
    if (number % 3 == 0 or number % 5 == 0 or number % 7 == 0) return 0;
    else{
        unsigned long max = ceil(sqrt(number));
        for (unsigned long i = 9; i <= max; i += 2){
            if (number % i == 0) return 0;
        }
        primeCounter++;

        //comment this out to have better performance
        cout<<number<<", ";
        return 0;
    }
}
