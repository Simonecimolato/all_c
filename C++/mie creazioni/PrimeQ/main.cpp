//PrimeQuestion
//Simone Cimolato, 07/10/2016

#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char** argv) {
	cout<<"Enter a positive integer (max: 18.446.744.073.709.551.615): ";
	unsigned long long number;
	double verifica;
	cin>>verifica;
	round(verifica);
	
		if (verifica <1 || verifica > 18446744073709551615) {
			cout<<"Invali input."<<endl;
			verifica=0;
			return main(argc, argv);
		} 
	number=verifica;
		if (number==1) {
			cout<<endl<<"1 is not prime."<<endl<<endl;
		}
		else {
			int radQ;
			radQ=round(sqrt(number)+0.5);
			int Div=2;
			int Resto;
			while (Div<=radQ) {
				Resto=number%Div;
				if (Div==radQ) {
                                cout<<endl<<number<<" is prime."<<endl<<endl;
                                return 0;
       			}
       			if (Resto==0) {
                                cout<<endl<<number<<" is not prime"<<", it is divisible by "<<Div<<"."<<endl<<endl;
                                return 0;
				   }
   			Div++;
		}
		  
	}
        return 0;
}
