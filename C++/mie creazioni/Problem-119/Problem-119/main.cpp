//
//  main.cpp
//  Problem 119, Info:https://projecteuler.net/problem=119
//
//  Created by Simone Cimolato on 22/12/16.
//  Copyright © 2016 Simone Cimolato. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

const short int target = 30;
__int128_t number = 10;
__int128_t backup;
int sum;
double resault = 0;


typedef __int128 int128_t;

/*      UINT64_MAX 18446744073709551615ULL */
#define P10_UINT64 10000000000000000000ULL   /* 19 zeroes */
#define E10_UINT64 19

#define STRINGIZER(x)   # x
#define TO_STRING(x)    STRINGIZER(x)

std::ostream&
operator<<( std::ostream& dest, __int128_t value )
{
    std::ostream::sentry s( dest );
    if ( s ) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[ 128 ];
        char* d = std::end( buffer );
        do{
            -- d;
            *d = "0123456789"[ tmp % 10 ];
            tmp /= 10;
        } while ( tmp != 0 );
        if ( value < 0 ) {
            -- d;
            *d = '-';
        }
        int len = std::end( buffer ) - d;
        if ( dest.rdbuf()->sputn( d, len ) != len ) {
            dest.setstate( std::ios_base::badbit );
        }
    }
    return dest;
}


int main(int argc, const char * argv[]) {
   
    ofstream output;
    output.open("/Users/simonecimolato/Desktop/Resaults.txt");      //this is my desktop, change this path to wherever you want to save the resaults.txt file
    
    if (output.fail()) {
        cout<<"An error occurred while opening the output file "<<endl;
        return 1;
    }
    output<<"Resaults."<<endl<<"Info: https://projecteuler.net/problem=119."<<endl<<"Code: https://github.com/Simonecimolato/Problem-119."<<endl<<endl;
    cout<<"Resaults."<<endl<<"Info: https://projecteuler.net/problem=119."<<endl<<"Code: https://github.com/Simonecimolato/Problem-119."<<endl<<endl;

    for(int i = 1; i < target; number++) {
        
        backup = number;
        resault = number;
        sum = 0;
        
        //calculating the sum of the digits
        while (number > 0){
            sum += number % 10;
            number /= 10;
        }
        
        //restoring the backup
        number = backup;
        
        if (sum == 1) {
            number++;
            sum++;
        }
        
        int exp;
        exp = 0;
        
        if (number % (sum * sum) == 0) {
            while (resault > 1){
                resault /= sum;
                exp++;
            }
            if (resault == 1){
                cout<<"number: "<<number<<"     sum: "<<sum<<"      exp: "<<exp<<"      index: "<<i<<endl;    //output to the console
                output<<"number: "<<number<<"     sum: "<<sum<<"      exp: "<<exp<<"      index: "<<i<<endl;  //output to the txt file
                i++;
            }
        }
    }
    cout<<"index 30 is: "<<number<<endl;
    output<<"index 30 is: "<<number<<endl;
    output.close();
    return 0;
}
