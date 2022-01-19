/*
Scrivere un algoritmo in C/C++ che risolve il seguente problema:
Dato un elenco di articoli di cui viene fornito in input 
  Nome, Prezzo, Quantità, AliquotaIVA (valori possibili: 4%, 10%, 22%). 
  Calcolare importo totale, comprensivo dell’IVA, e l’IVA totale. 
*/


#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#define MAX 20
using namespace std;
string minuscolo(string s)
{
	for (unsigned i = 0; i < s.size(); ++i)
		s[i] = tolower(s[i]);
	return s;
}
int main()
{
	int P=0; 
	string nomeprodotto[MAX];
	double prezzo[MAX];	
	double iva[MAX];		
					
	int quantita[MAX];
	double importo;		
	double importo_totale=0;	

	cout<<"inserirsci il nome prodotto"<<" (Stop per terminare l'inserimento di prodotti) \n" << endl;
	//	cin>>nomeprodotto[P]; // legge fino al primo spazio
	getline(cin, nomeprodotto[0]); //legge l'intera linea e la memorizza in nomeprodotto[P]
    cout<<"nomeprodotto["<<0<<"] trasformato in minuscolo ="<< minuscolo(nomeprodotto[P])<< endl;

	while(minuscolo(nomeprodotto[P]) != "stop")
	{
		cout<<"inserisci il prezzo del prodotto"<<endl;
		cin>>prezzo[P];	

		cout<<"inserisci la quantita  del prodotto comprato"<<endl;
		cin>>quantita[P];

   do {
		cout<<"inserisci aliquota IVA"<<endl;
		cin>>iva[P];
		cin.ignore(255,'\n'); // per evitare eventuali problemi con getline
     } while(iva[P]!=4 && iva[P]!=10 && iva[P]!=22);

		P=P+1;
		cout<<"inserirsci il nome prodotto"<<" (Stop per terminare l'inserimento di prodotti) \n" << endl;
	    getline(cin, nomeprodotto[P]); //legge l'intera linea e la memorizza in nomeprodotto[P]
//        cin>>nomeprodotto[P];
        cout<<"nomeprodotto["<<P<<"] trasformato in minuscolo ="<< minuscolo(nomeprodotto[P])<< endl;
	}

if (P!=0){
	cout<<"DescrizioneProdotto, Prezzo, Quantità, AliquotaIVA, Importo (cioe' prezzo + IVA) "<<endl; 
	 cout << setiosflags(ios::left);
	for(int k=0; k<P;k++)
	{  
	  cout<< setw(20)<<nomeprodotto[k] <<"   "; 
	  cout<< setw(6)<<prezzo[k] <<"   "; 
	  cout<< setw(10)<<quantita[k] <<"   "; 
	  cout<< setw(12)<<iva[k]<<"   "; 
		
		importo = prezzo[k] * quantita[k] + prezzo[k] * quantita[k] * (iva[k] / 100);	
		cout<< setw(8)<<importo<<endl; 
		importo_totale=importo_totale+importo;
	}

	cout<<"l'importo totale e' di: "<<importo_totale<<" Euro"<<endl;
  } else cout<<"Nessun prodotto inserito ";


	return 0;
}	
