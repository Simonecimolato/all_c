//
//  main.cpp
//  Leibniz's pi
//
//  Created by Simone Cimolato on 27/01/18.
//  Copyright © 2018 Simone Cimolato. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, const char * argv[]) {
    cout.precision(101);
    
    double pi = 0;
    clock_t start = clock();

    for (int i = 0; i <= 1000000000; i++) {
        pi += pow(-1,i) / (2*i + 1);
    }
    pi*=4;
    
    clock_t end = clock();
    double time = (double) (end-start) / CLOCKS_PER_SEC;

    cout<<pi<<endl<<endl;
    cout.precision(5);
    cout<<"Time taken: "<<time<<" seconds"<<endl;
    
    return 0;
}
