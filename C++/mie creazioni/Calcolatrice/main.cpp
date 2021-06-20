//Calculator
//Simone Cimolato, 25/09/2016

#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	cout<<"Cosa vuoi fare?:"<<endl<<endl;
	cout<<"[1] Moltiplicazione. "<<endl;
	cout<<"[2] Divisione. "<<endl;
	cout<<"[3] Addizione. "<<endl;
	cout<<"[4] Sottrazione. "<<endl<<endl;
	cout<<"Inserisci il numero corrispondente: ";
	int scelta;
	cin>>scelta;  

	float elemento;
	float elemento2;
	double risultato;
	char altro='y';
			
	switch (scelta) {
		case (1):
				cout<<"Inserisci il 1 fattore: ";
				cin>>elemento;
				cout<<"Inserisci il 2 fattore: ";
				cin>>elemento2;
				risultato = elemento*elemento2;
				cout<<"Vuoi inserire un altro fattore? [Y] Yes. [N] No. ";
				cin>>altro;
				cout<<endl;
				for (int k=3; altro=='Y' or altro=='y'; k++) {
				cout<<"Inserisci il "<<k<<" fattore: ";
				cin>>elemento;
				risultato *= elemento;
				cout<<endl;
				cout<<"Vuoi inserire un altro fattore? [Y] Yes. [N] No. ";
				cin>>altro;
				cout<<endl;
			}
			cout<<"Il prodotto e': "<<risultato<<endl<<endl;
			break;
			
		case (2):
			cout<<"Inserisci il dividendo: ";
				cin>>elemento;
				cout<<"Inserisci il divisore: ";
				cin>>elemento2;
				risultato = elemento/elemento2;
				cout<<"Vuoi inserire un altro divisore? [Y] Yes. [N] No. ";
				cin>>altro;
				cout<<endl;
				for (int D=3; altro=='Y' or altro=='y'; D++) {
				cout<<"Inserisci il "<<D<<" divisore: ";
				cin>>elemento;
				risultato /= elemento;
				cout<<endl;
				cout<<"Vuoi inserire un altro divisore? [Y] Yes. [N] No. ";
				cin>>altro;
				cout<<endl;
			}
			cout<<"Il quoziente e': "<<risultato<<endl<<endl;
			break;
		case (3):
			cout<<"Inserisci il primo addendo: ";
				cin>>elemento;
				cout<<"Inserisci il secondo addendo: ";
				cin>>elemento2;
				risultato = elemento+elemento2;
				cout<<"Vuoi inserire un altro addendo? [Y] Yes. [N] No. ";
				cin>>altro;
				cout<<endl;
				for (int G=3; altro=='Y' or altro=='y'; G++) {
				cout<<"Inserisci il "<<G<<" addendo: ";
				cin>>elemento;
				risultato += elemento;
				cout<<endl;
				cout<<"Vuoi inserire un altro addendo? [Y] Yes. [N] No. ";
				cin>>altro;
				cout<<endl;
			}
			cout<<"Il risultato e': "<<risultato<<endl<<endl;
			break;
		case (4):
			cout<<"Inserisci il minuendo: ";
				cin>>elemento;
				cout<<"Inserisci il sottraendo: ";
				cin>>elemento2;
				risultato = elemento-elemento2;
				cout<<"Vuoi inserire un altro numero? [Y] Yes. [N] No. ";
				cin>>altro;
				cout<<endl;
				for (int F=3; altro=='Y' or altro=='y'; F++) {
				cout<<"Inserisci il "<<F<<" numero: ";
				cin>>elemento;
				risultato -= elemento;
				cout<<endl;
				cout<<"Vuoi inserire un altro numero? [Y] Yes. [N] No. ";
				cin>>altro;
				cout<<endl;
			}
			cout<<"Il risultato e': "<<risultato<<endl<<endl;
			break;
		default:
			cout<<"Input non valido."<<endl<<endl;
			return main(argc, argv);
	}
	system("PAUSE");
	return 0;
}
