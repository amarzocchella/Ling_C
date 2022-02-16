#include <iostream>
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

void elabora_frase(string s1, int length){
  printf("lunghezza s1: %d;  sizeof(s1) = %d;\n",length, sizeof(s1));
//  int LunghezzaStringa = sizeof(s1);// mi darebbe un risultato errato!
  int i = 0;
  while (i<length ){
 //  printf("s1[ %d ] = %c ",i, s1[i]);
    printf("%c ",s1[i]);
  i++;
   }
  printf(";\n Lunghezza Parola: %d \n", length);
}//fine stampa_word


void stampa_word(char s1[]){
}//fine stampa_word

int main()
{
	int dim, i=0; 
	string frasi[MAX];

	cout<<"inserirsci una frase (Stop per terminare l'inserimento di frasi) \n" << endl;
	getline(cin, frasi[i]); //legge l'intera linea e la memorizza in frasi[i]
 //   cout<<"frasi["<<i<<"] trasformato in minuscolo ="<< minuscolo(frasi[i])<< endl;// serve per i test.
	while(minuscolo(frasi[i]) != "stop")
	{	dim = sizeof(frasi[i]);
		//elabora_frase(frasi[i],dim);
		//stampa_word (frasi[i]);
	//	printf("Frase letta: %s\n Lunghezza Parola: %d \n",frasi[i], dim);
		cout<<frasi[i]<< endl;
		i++;
		cout<<"inserirsci una frase (Stop per terminare l'inserimento di frasi) \n" << endl;
	    getline(cin, frasi[i]);
	}

if (i!=0){ // abbiamo almeno una frase elaborata!
	cout<<"Frasi elaborate. "<<endl; 
	for(int k=0; k<i;k++)
	{  
	  cout<< k+1<<") "<<setw(-255)<<frasi[k] <<endl; 
	}
  } else cout<<"Nessuna frase inserita.";

	return 0;
}	
