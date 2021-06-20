//
//  main.cpp
//  Pi using primes
//
//  Created by Simone Cimolato on 20/05/17.
//  Copyright © 2017 Simone Cimolato. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <math.h>
#include <limits>
#include <iomanip>
using namespace std;

int gcd(int a, int b);

int main(int argc, const char * argv[]) {

    srand(static_cast<unsigned int>(time(NULL)));
    rand(); //the first time i call the function it always returns the same number

    int total = 100000000;
    int coprimes = 0;
    cout<<"Numbers generated: "<<total * 2<<endl;
    cout<<"ETA: ~"<<0.0000002684 * total<<" seconds"<<endl<<endl;   //on my computer
    clock_t begin = clock();
    
    //generating random numbers and checking if they are coprime or not
    for (int i = 0; i <= total; i++){
        int first = rand();
        int second = rand();
        if (gcd(first, second) == 1) coprimes++;
    }
   
    //calculating pi
    double pi = sqrt(6.0/((double)coprimes/(double)total));
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    
    cout<<"Pi approx: "<<setprecision(20)<<pi<<endl       //another really great approximation of pi is just 355/113, lol
        <<"Precision: "<<100 - fabs(100 - (pi/3.14159265358979323846)*100)<<"%"<<endl<<endl
        <<"Time spent: "<<setprecision(4)<<time_spent<<" seconds."<<endl<<endl;
    return 0;
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
