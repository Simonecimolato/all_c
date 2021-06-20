// Sum of Primes.cpp
//Simone Cimolato, 26/09/2016

#include <iostream>
#include <math.h>
using namespace std;

double risultato;

int main()
{
	long long limite;
	cout<<"Enter a positive integer."<<endl<<"I am going to calculate the sum of all the primes below that number (max: 18446744073709551615): ";
	cin>>limite;
	if (limite<1 || limite> 18446744073709551615) {
		cout<<"Invalid input."<<endl<<endl;
		limite=0;
		return main();	
	}
	else if (limite==1) {
		cout<<"The sum of all the primes below 1 is: 0."<<endl;
		system("PAUSE");
		return 0;
	}
	round(limite);
	
	for (long long Numero = 3; Numero <= limite; Numero += 2) {
		for (long long Divisore = 3; Divisore <= Numero; Divisore += 2) {
				if (Numero % Divisore == 0) break;                           //not prime.
				else if (Numero == Divisore + 2) {                           //prime.
				risultato += Numero;
			}
		}
		int percentuale = (Numero * 100) / limite;
		cout << percentuale << "% done. \r";
		}
		risultato+=5;
	cout<<"The sum of all the primes below "<<limite<<" is: "<<risultato<<endl<<endl;
	system("PAUSE");
	return 0;
}
