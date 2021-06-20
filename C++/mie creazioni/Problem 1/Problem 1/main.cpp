//
//  main.cpp
//  Problem 1
//
//  Created by Simone Cimolato on 27/12/16.
//  Copyright © 2016 Simone Cimolato. All rights reserved.
//

#include <iostream>
using namespace std;

const long target = 1000000000;

int main(int argc, const char * argv[]) {
    long res;
    long sum = 0;
    clock_t start = clock();

    //multiples of 3
    for (long i = 1; 3 * i <= target; i++) {
        res = 3 * i;
        sum += res;
    }
    res = 0;
    //multiples of 5
    for (long j = 1; 5 * j <= target; j++) {
        res = 5 * j;
        sum += res;
    }
    clock_t end = clock();
    double time = (double) (end-start) / CLOCKS_PER_SEC;

    cout<<sum<<endl<<endl<<endl
    <<time<<" seconds."<<endl<<endl;
    return 0;
}
