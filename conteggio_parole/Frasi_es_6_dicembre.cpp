/* file: Frasi_es_6_dicembre.cpp
   Leggere e visualizzare frasi
   * 
Frase da usare per i test non banali:
Ciao, come va con la programmazione, è dura, vero?
   *
   * Attenzione legge stringhe con spazi, cioe' frasi vere e proprie!. 
*/
#include <iostream>
#include <string>
#define max 15
using namespace std;
string frase[max];
int scelta, conta_omar_c, conta_omar_p, j, i, cont =0;
int main()
  { /* inizio programma */
      cout<< "Ciao 'piccolino', dammi una frase! (stop per terminale) "; 
      getline(cin,frase[cont]);
//		cin.ignore(255,'\n'); // per evitare eventuali problemi con getline
  while (frase[cont]!="stop"){
	  /*leggo una frase incremento il contatore delle frasi lette
	   * e poi ripeto il ciclo*/
	   cont++;
      cout<< "Ciao 'piccolino', dammi una frase! (stop per terminale) "; 
      getline(cin,frase[cont]);
	  }
  for(i=0; i< cont; i++){
	  cout<< "Stampo la frase "<<i+1<<": "<<frase[i] <<endl;
	  }

 for(i=0; i< cont; i++){
	  j=0; conta_omar_c=0; conta_omar_p=1;
      while (frase[i][j]!='\0'){
	 if (frase[i][j] ==' ') {conta_omar_c++; conta_omar_p++;}
		else {conta_omar_c++; }
		j++;
		}
    cout<< "Ciao 'piccolino'! Il numero di caratteri della frase "<<i+1<<" = "<<conta_omar_c<<endl; 
    cout<< "Ciao 'piccolino'! Il numero di parole della frase  "<<i+1<<" = "<<conta_omar_p<<endl; 
	}
   if (cont>0){
    cout<< "Vuoi stampare una frase? dammi un numero fra 0 e "<<cont -1<<endl; 
	cin >>scelta;
	if ((scelta >=0) && (scelta <cont)) 
		{ cout<< "Stampo la frase "<<scelta<<": "<<frase[scelta] <<endl;}
	else {cout<< "Valore immesso errato! "<<endl;}
	}
    cout<< "Fine programma. Ciao 'piccolino'!"<<endl; 
return 0;
} /* fine programma */
