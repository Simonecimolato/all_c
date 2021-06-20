//Numeri primi
//Simone Cimolato, 31/07/2016.

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

const unsigned long long verifica=18446744073709551615;
long double a,count,scelta,d,numero0;
unsigned long long numero,c=2,Div,Number,limite,radQ;
string lista;

int main () {

cout<<"Ciao."<<endl
    <<endl;
    
inizio:
    
cout<<"Cosa vuoi fare?"<<endl
    <<endl
    <<"1. Verificare che un numero sia primo."<<endl
    <<"2. Trovare tutti i numeri primi prima di un certo limite."<<endl
    <<endl;

scelta:
cout<<"Scelta (1 o 2): ";
cin>>scelta;


if (scelta !=1 and scelta !=2) {
	cout<<"Input non valido."<<endl;
	cout<<endl;
	goto scelta;
}

if (scelta==1) {
	cout<<endl;
	cout<<endl;
	numero1:
	numero0=0;
	cout<<"Numero da verificare (massimo: "<<verifica<<") : ";
	cin>>numero0;
	if (numero0<verifica and numero0>=1) {
	numero=numero0;
	radQ=ceil(sqrt(numero0+0.5));
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

	while (c<=radQ) {
		d=numero%c;
        if (c==radQ) {
            cout<<endl;
            cout<<numero<<" e' primo."<<endl;
            cout<<endl;
            break;
        }
		if (d==0) {
    	cout<<endl;
		cout<<numero<<" non e' primo";
    	cout<<", e' divisibile per "<<c<<"."<<endl;
		cout<<endl;
    	break;
		}
        c++;
	}
}

else if (scelta==2) {
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
	cout<<"Vuoi la lista dei numeri primi trovati?  (Y) Yes.  (N) No. : ";
	cin>>lista;

	if ((lista=="y" or lista=="Y")and limite>2) cout<<"2, 3, ";

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
	for (Number=3;Number<=limite;Number+=2) {
         for (Div=3;Div<=Number;Div+=2) {
			 if (Number%Div==0) break;
			 	else if (Number==Div+2) {
             		count++;
					if (lista=="Y" or lista=="y") {
						cout<<Number<<", ";
					}
			    	else if (lista=="n" or lista=="N") {
			    		a=Number;
			    		if ((lista=="N" or lista=="n")and limite>100000) {
			    			int percentuale;
							percentuale=(Number*100)/limite;
							cout<<percentuale<<"% fatto. \r";
					}
				} 
	 		}
	}
}
}

	if ((lista=="N" or lista=="n") and limite>100000) {
	cout<<"100% fatto."<<endl;
	}
	if ((lista=="N" or lista=="n") and limite>2) cout<<"Ultimo numero primo prima di "<<limite<<": "<<a<<endl;
	cout<<endl;
	if (limite>2) cout<<"I numeri primi sono: "<<count+2<<endl;
	cout<<endl;
}
return 0;
}
