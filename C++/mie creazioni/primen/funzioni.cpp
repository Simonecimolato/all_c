#include <iostream>
using namespace std;
extern unsigned long long c,numero;
extern long double d;

void primo(int radQ) {
		while (c<=radQ) {
		d=numero%c; 
        if (c==radQ) {                      //primo.
            cout<<endl;
            cout<<numero<<" e' primo."<<endl;
            cout<<endl;
            break;
        }
		if (d==0) {          //non primo.
    	cout<<endl;
		cout<<numero<<" non e' primo";
    	cout<<", e' divisibile per "<<c<<"."<<endl;
		cout<<endl;
    	break;
		}
        c++;
	}
}
