
	cout<<"vuoi la lista dei numeri primi trovati? (y/n) : ";    //opzione lista numeri primi.
	cin>>lista;
	file1:
	cout<<"vuoi creare un  file di testo sul desktop con i numeri primi? (altrimenti verranno stampati direttamente nella console) (s/n)";
	cin>>file;
	if (file !='y' and file !='n') {
	cout<<endl;
	cout<<"input non valido."<<endl;
	cout<<endl;
	goto file1;
}
	if (file=='y') {
		ofstream primi_trovati("C:/Users/Utente/Desktop/primi trovati.txt",ios::out);                               //c'è un problema con lo scope di primi_trovati, in quanto non è raggiungibile dalla parte successiva del programma, (ciclo for per trovare i numeri)
		if (!primi_trovati) {                                                                                       // non posso però modificare le parentesi di questi due IF, perche se lo facessi eseguirebbe la parte sucessiva 
			cout<<"Errore nella scrittura del file, i numeri verranno stampati nella console."<<endl;               //del programma solo se la condizione dell'if fosse vera.
			file='n';
		}
	}
	
	
	if (lista=='y') cout<<"2, 3, ";

	if (lista !='y' and lista !='n') {
	cout<<endl;
	cout<<"input non valido."<<endl;
	cout<<endl;
	goto lista1;
}

    else {
	for (i=3;i<=limite;i+=2) {                         //calcolo
         for (j=3;j<=i;j+=2) {
			 if (i%j==0) break;                         //non primo.
             	else if (i==j+2) {                      //primo.
             		b++;
					if (lista=='y'and file=='y') {
						cout<<i<<", ";
						primi_trovati<<i<<", ";
					}
					else if (lista=='y'and file=='n') {
					 cout<<i<<", ";
			    	}
			    	else if (lista=='n'and file=='y') {
						primi_trovati<<i<<", ";
					}
			    	else if (lista=='n'and file=='n') {
			    		a=i;
			    		if (lista=='n' and limite>200000) {
			    			percentuale=(i*100)/limite;              //calcolo e stampaggio percentuale modificando sempre il numero impostando il cursore all'inizio. (\r)
							cout<<percentuale<<"% fatto. \r";
					}
				} 
	 		}
		}
	}

	if (lista=='n' and limite>=200000) {
	cout<<"100% fatto."<<endl;
	}
	if (lista=='n') cout<<"ultimo numero primo prima di "<<limite<<": "<<a<<endl;    //ultimo numero primo prima del limite imposto.
	cout<<endl;
	cout<<"i numeri primi sono: "<<b+2<<endl;    //numero di numeri primi entro il limite.
	cout<<endl;
	}
}

fine1:
if (file=='y') {
	primi_trovati.close()
	cout<<"scrittura sul file completata con successo."<<endl;
}

