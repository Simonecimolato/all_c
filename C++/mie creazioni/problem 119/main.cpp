//
//  main.cpp
//  summer
//
//  Created by Simone Cimolato on 22/12/16.
//  Copyright © 2016 Simone Cimolato. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

const int target = 30;
unsigned long long number = 20;
unsigned long sum;
unsigned long long backup;
unsigned long long ris = 0;

int main(int argc, const char * argv[]) {
    
    for(int i = 1; i < target; number++) {
        
        backup = number;
        sum = 0;
        ris = 0;
        
        while (number > 0){
            sum += number % 10;
            number /= 10;
        }

        number = backup;
        
        if (sum == 1) {
            number++;
            sum++;
        }

        for (long exp = 1; ris < number; exp++){
            ris = pow(sum, exp);
            if (ris == number) {
                cout<<"number: "<<number<<"		exp: "<<exp<<"		sum: "<<sum<<"		index: "<<i<<endl;
                i++;
            }
        }
    }
    cout<<"a 30 is: "<<number<<endl;
    return 0;
}
