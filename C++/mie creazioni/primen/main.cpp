//Numeri primi
//Simone Cimolato, 31/07/2016.

#include <iostream>
#include <string>
#include <math.h>
#include "funzioni.cpp"

using namespace std;

const unsigned long long verifica=18446744073709551615;
long double count,d;
unsigned long long c=2,numero,Div,i,radQ,limite,a;
string lista;

int main () {

cout<<"Ciao."<<endl
    <<endl;

inizio:

cout<<"Cosa vuoi fare?"<<endl
    <<endl
    <<"1. Verificare che un numero sia primo."<<endl
    <<"2. Trovare tutti i numeri primi prima di un certo numero."<<endl
    <<endl;

scelta:
long double scelta;
cout<<"Scelta (1 o 2): ";
cin>>scelta;


if (scelta !=1 and scelta !=2) {
	cout<<"Input non valido."<<endl;        //prima scelta.
	cout<<endl;
	goto scelta;
}

if (scelta==1) {
	cout<<endl;
	cout<<endl;
	numero1:
	long double numero0=0;
	cout<<"Numero da verificare (massimo: "<<verifica<<") : ";
	cin>>numero0;
	if (numero0<verifica and numero0>=1) {
	numero=numero0;
	numero0=sqrt(numero0+0.5);
	radQ=round(numero0);
}

else if (verifica<numero0 or numero0<=1){
cout<<"Input non valido."<<endl;
cout<<endl;
goto numero1;
}

if (numero==1) {
	cout<<endl;
	cout<<"1 non e' primo."<<endl;
	cout<<endl;
}
primo(radQ);
}

if (scelta==2) {
	limite1:
	cout<<endl;
	cout<<endl;
	cout<<"Limite numerico (massimo: "<<verifica<<") : ";
	cin>>limite;
	if (1>limite) {
	cout<<"Input non valido."<<endl;
	goto limite1;
}
	if (limite==1) {
		cout<<"Non ci sono numeri primi prima di 1, e 1 non e' primo ;)"<<endl;
		goto limite1;
	}

	lista1:
	cout<<"Vuoi la lista dei numeri primi trovati?  (Y) Yes.  (N) No. : ";    //list
	cin>>lista;
	bool YesOrNo;
	if ((lista=="y" or lista=="Y")and limite>2) {
		YesOrNo=true;
		cout<<"2, 3, 5, 7, ";
	}
	else if ((lista=="N" or lista=="n")and limite>2) YesOrNo=false;
	if (lista !="Y" and lista!="y" and lista!="N" and lista !="n") {
	cout<<endl;
	cout<<"Input non valido."<<endl;
	cout<<endl;
	goto lista1;
}

	if (limite==2) {
		if (lista!="n" and lista!="N" and lista!="Y" and lista !="y") goto lista1;
		if (lista=="Y" or lista=="y") {
		cout<<"2,"<<endl;
		}
		if (lista=="N" or lista=="n") {
			cout<<endl;
			cout<<"Non ci sono numeri primi prima di 2."<<endl;
		}
		cout<<endl;
		cout<<"I numeri primi sono: 1"<<endl;
	}

if (limite>2){
long long radN;
	switch (YesOrNo) {
		case true: {
		for (i=3;i<=limite;i+=2) {                                //TODO: MIGLIORARE IL SISTEMA DELLA RADICE QUADRATA, NON TROVA TUTTI I NUMERI, INOLTRE IL COUNTER +=4
			radN=round(sqrt(i));
   			if (radN<9) radN=9;
  		 		for (Div=3;Div<=radN;Div+=2) {
			 		if (i%Div==0) break;
		 				else if (radN==Div+2) {				//prime.
           					count++;
							cout<<i<<", ";
 					}
				}
			}
			break;
		}
			case false: {
				for (i=3;i<=limite;i+=2) {
					radN=round(sqrt(i));
	  				 if (radN<9) radN=9;
	  				 for (Div=3;Div<=radN;Div+=2) {
			 			if (i%Div==0) break;
			 			else if (radN==Div+2) {				//prime.
             			 	count++;
			    			a=i;
			    		if (limite>5000000) {
			    			int percentuale=(i*100)/limite;
							cout<<percentuale<<"% fatto. \r";
						}
					}
	 			}
			}
			break;
		}
			default: {
				return 1;
			}
		}
	}
	if (YesOrNo==false and limite>5000000) {
	cout<<"100% fatto."<<endl;
	}
	if ((lista=="N" or lista=="n") and limite>2) cout<<"Ultimo numero primo prima di "<<limite<<": "<<a<<endl;
	cout<<endl;
	if (limite>2) cout<<"I numeri primi sono: "<<count+1<<endl;
	cout<<endl;
}
return 0;
}
