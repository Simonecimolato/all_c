//
//  main.cpp
//  test infinito
//
//  Created by Simone Cimolato on 25/01/17.
//  Copyright © 2017 Simone Cimolato. All rights reserved.
//

//Simone Cimolato, 29/07/2016.
//Paradosso (in)finito

#include <iostream>
#include <unistd.h>
#include <string>

using namespace std;

double tempo = 1;  //seconds
int iteration = 1;
int tot;
string scelta;

int main() {
    
    cout<<"iterazione n:     "<<"tempo (s):"<<endl;
    cout<<endl;
    
    while (tempo!= 0){
        cout << iteration <<"                 " << tempo << endl;
        sleep(tempo);
        tempo = tempo/2;
        iteration++;
    }
    
    cout<<endl;
    cout <<"iterazioni totali: "<< iteration<<endl;
    cout<<endl;
    
fine:
    cout<<"Vuoi ricominciare?  (Y) Yes. (N) No. : ";
    cin>>scelta;
    
    if (scelta=="Y" or scelta=="y") {
        tempo = 1;    //seconds
        iteration = 1;
        cout<<endl<<endl<<endl<<endl;
        return main();
    }
    else if(scelta=="N" or scelta=="n") {
        return (0);	
    }
    else {
        cout<<"input non valido"<<endl;
        cout<<endl;
        goto fine;
    }
}
