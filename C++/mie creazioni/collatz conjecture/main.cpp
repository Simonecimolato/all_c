//The Collatz conjecture
//Simone Cimolato, 09/08/2016

#include <iostream>
#define STEP 100000000  //100 million

using namespace std;

long long n;                     //you can turn the variable to long double if you want to try with bigger numbers, but it will print the number in scientific notation
int count,ver;                   //try changing n into 63728127 :)
int step = 1000000000/STEP;

bool even (int n);
int collatzOnOneNumber();
int trueCollatz();

int main() {
    //collatzOnOneNumber();
    trueCollatz();
    return 0;
}

int collatzOnOneNumber(){
    cout<<"Insert a number: ";
    cin>>n;
    cout<<n<<endl;

    if (n>0) {
        ver=1;
    }

    while (n!=1 and n!=-1 and n!=0) {

        if(n<0 and ver==1) {
            cout<<"Overflow, your number is too large."<<endl;
            return 1;
        }

         if (even(n)) {
            n/=2;                   //n/2
            cout<<n<<endl;
            count++;
         }
         else {
            n=(n*3)+1;              //3n+1
            cout<<n<<endl;
            n/=2;                   //after 3n+1 we always get an even number, n=n/2 without checking again
            count+=2;
            cout<<n<<endl;
         }
    }
    cout<<endl;
    cout<<"Total steps required: "<<count<<endl<<endl;
    //system("PAUSE");
}

int trueCollatz(){
    long long x = 3;
    float k = 0;
    long long n;

    while(x<LLONG_MAX){
        for(;x<k*STEP;x+=2){

            n = ((x*3)+1)/2;

            while (n>=x){
                if (n%2==0)n/=2;       //n/2
                else n=((n*3)+1)/2;     //after 3n+1 we always get an even number, n=n/2 without checking again
            }
        }
        //there is not an if checking to see if it's solved cause i'm pretty sure if there is a number that doesnt go to 1 it's not below LLONG_MAX lol
        cout<<"progress (bln): "<<k/step<<endl;
        k+=1;
    }


    return 0;
}

