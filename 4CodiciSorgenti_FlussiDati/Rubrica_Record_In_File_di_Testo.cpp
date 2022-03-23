// Rubrica_Record_In_File_di_Testo.cpp: gestione di una rubrica telefonica
// inserimento, aggiunta, visualizzazione,
// stampa e ricerca
/*
Il programma salva i record in un file di testo di nome "rubrica_record.dat" 
inserendo i valori degli attributi in un'unica riga 
separati dal carattere speciale #.
Il formato delle line di testo è il seguente:
Nome completo poi # ed il numero di telefono. Es.:
Ciccio Pasticcio#0471343625
Palla Pallina#333372866

In una versione successiva si pottrebbe usare un file binario e salvare i record 
direttamente. 
Ma attenzioe: onde evitare problemi in lettura dal file, occorre evitare 
di usare attributi di tipo string e la dove necessario 
usare array di char di dimensione opportuna!


es.:
struct dati
{
	char nome[25]; // inteso come cognome + nome
	char  telefono[14];
};

Lascio a voi la realizzazione della versione che salva nel file i record direttamente.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstring>
#include <string.h>
#include <stdlib.h> 

using namespace std;
#define MAX 1000
const string NOMEARCH = "rubrica_record.dat";
fstream archivio; // dichiara stream
string nome, telefono;
struct dati
{
	string nome; // inteso come cognome + nome
	string telefono;
};
dati persona[MAX]; 
int indice=0, ContaRecord=0;
string riga_letta;
// prototipi delle funzioni
int Menu();
int MenuInit();
void Crea();
void Aggiungi();
void VisualizzaFile();
void Stampa();
void RicercaDaArray();
void RicercaDaFile();
void parse(string riga_letta,dati &PersTmp);
void parse_studio(string riga_letta);
void carica_dati_studio();
void parse(string riga_letta); 
void carica_dati(); 
int mystrlen(string s);//(const char *s);
void VisualizzaReport_cout();
void VisualizzaReport_printf();
// funzione principale
int main ()
{	int CaricaDati=0;
	int scelta;
		do {
		scelta = MenuInit();
		switch (scelta) {
		case 1:
		    ContaRecord=0;
			carica_dati_studio();
			VisualizzaReport_cout();
			VisualizzaReport_printf();
			CaricaDati=1;
			break;
		case 2:
		    ContaRecord=0;
			carica_dati();
			VisualizzaReport_cout();
			VisualizzaReport_printf();
			CaricaDati=2;
			break;
		case 3:
			cout << "fine carica dati" << endl;
			break;
		}
	} while (scelta!=3);

	do {
		if (CaricaDati==0)
		{	ContaRecord=0;
			CaricaDati=3;// Deve caricare i dati solo una volta. 
			carica_dati();
			VisualizzaReport_cout();
			VisualizzaReport_printf();
		}
		scelta = Menu();
		switch (scelta) {
		case 1:
			Crea();
			break;
		case 2:
			Aggiungi();
			break;
		case 3:
			VisualizzaFile();
			break;
		case 4:
			Stampa();
			break;
		case 5:
			RicercaDaArray();
			break;
		case 6:
			RicercaDaFile();
			break;
		case 7:
			VisualizzaReport_cout();
		case 8:
			VisualizzaReport_printf();
		case 9:
			cout << "fine lavoro" << endl;
			break;
		}
	} while (scelta!=9);
	return 0;
}
// menu scelta iniziale
int MenuInit()
{
	int s;
	 printf("%100s \n\n", "Questo programma ha solo uno scopo didattico  e le scelte fatte vanno viste in tale ottica!!!");
	cout << "--------------------------" << endl;
	cout << "Gestione rubrica telefonica" << endl;
	cout << "1. Carica dati con carica_dati_studio()" << endl;
	cout << "2. Carica dati con carica_dati()" << endl;
	cout << "3. Fine Carica dati" << endl;
// scelta dell'utente
	cout << "Scegli: ";
	cin >> s;
	cout << "--------------------------" << endl;
	return s;
} // MenuInit

// menu delle scelte
int Menu()
{
	int s;
	printf("%100s \n\n", "Questo programma ha solo uno scopo didattico  e le scelte fatte vanno viste in tale ottica!!!");
	cout << "--------------------------" << endl;
	cout << "Gestione rubrica telefonica" << endl;
	cout << "1. Creazione rubrica" << endl;
	cout << "2. Aggiunta nuovi nomi" << endl;
	cout << "3. Visualizzazione rubrica da file" << endl;
	cout << "4. Stampa rubrica" << endl;
	cout << "5. Ricerca di nomi in array" << endl;
	cout << "6. Ricerca di nomi in file" << endl;
	cout << "7. Visualizza Report con cout" << endl;
	cout << "8. Visualizza Report con printf" << endl;
	cout << "9. Fine lavoro" << endl;
// scelta dell'utente
	cout << "Scegli: ";
	cin >> s;
	cout << "--------------------------" << endl;
	return s;
} // Menu
// creazione archivio
void Crea()
{
	/*
	 * Attenzione!! Inserire un controllo per verificare se il file esiste già 
	 * ed in tal caso lo apriamo in modalità append
	 * altrimenti perdiamo i record inseriti in una precedente 
	 * sessione di lavoro!!!
	 * Per controllare ti puoi aiutare con il tipo File del C standard 
	 * che ti mette a disposizione una serie di funzioni predefinite molto utili.
	 * 
	 */

	archivio.open(NOMEARCH.c_str(), ios::out); // apre il file per la scrittura
	cout << "Inserisci un nome (* = fine): ";
	getline(cin,persona[indice].nome);
	while ((nome != "*")&&(indice<MAX)) {
		cout << "Telefono: ";
		cin >> persona[indice].telefono;
		ContaRecord=indice;
		archivio << persona[indice].nome << "#" << persona[indice].telefono << endl; // scrive sul file
		indice++;
		if (indice<MAX){
			cout << "Inserisci un altro nome (* = fine): ";
			cin.ignore(255,'\n'); // per evitare eventuali problemi con getline
			getline(cin,persona[indice].nome);
			}
	}
	archivio.close(); // chiude il file
} // Crea
// aggiunta di dati all'archivio
void Aggiungi()
{
	archivio.open(NOMEARCH.c_str(), ios::out | ios::app); // apre il file in append
	if (!archivio) {
		cout << "Errore nell'apertura del file" << endl;
	} else {
		cout << "Nome: ";
		ContaRecord=ContaRecord+1;
		indice=ContaRecord;
		getline(cin,persona[indice].nome);
		cout << "Telefono: ";
		cin >> persona[indice].telefono;
		archivio << persona[indice].nome << "#" << persona[indice].telefono << endl; // scrive sul file
		archivio.close(); // chiude il file
	}
} // Aggiungi
// lettura dei dati dall'archivio
void VisualizzaFile()
{
	archivio.open(NOMEARCH.c_str(), ios::in); // apre il file in lettura
	if (!archivio) {
		cout << "Errore nell'apertura del file" << endl;
	} else {
		getline(archivio,riga_letta);// legge dal file
		cout << riga_letta << endl; // stampa la stringa letta dal file
		while (!archivio.eof()) {
		getline(archivio,riga_letta);// legge dal file
		cout << riga_letta << endl; // stampa la stringa letta dal file
		getline(archivio,riga_letta);// legge dal file
		cout << riga_letta << endl; // stampa la stringa letta dal file
		}
		archivio.close(); // chiude il file
	}
} // Visualizza
void Stampa()
{
	 printf("%50s \n\n", "Stampa su LPT1  ");
	dati PersTmp;
	string riga_letta;
	ofstream stampante; // dichiara uno stream
	stampante.open("LPT1"); // apre lo stream della stampante
	archivio.open(NOMEARCH.c_str(), ios::in); // apre il file in lettura
	if (!archivio) {
		cout << "Errore nell'apertura del file" << endl;
	} else {
			 while (getline(archivio,riga_letta)) {
				parse(riga_letta, PersTmp);
				stampante << PersTmp.nome << "; tel. " << PersTmp.telefono << endl;
				cout << PersTmp.nome << ";  tel. " << PersTmp.telefono << endl;
			}
		archivio.close(); // chiude il file
		cout << "Stampa terminata" << endl;
	}
	stampante.close(); // chiude lo stream della stampante
	 printf("%50s \n\n", "Fine Stampa su LPT1  ");
} // Stampa

void RicercaDaArray()
{
	string cercato;
	bool trovato = false;
	cout << "Ricerca in Array "<< endl;
  if(ContaRecord!=0){
	 cin.ignore(255,'\n'); // per evitare eventuali problemi con getline
	cout << "Inserisci il nome da cercare: ";
	getline(cin,cercato); int k=0;
	while ((k<ContaRecord) && !trovato)
	  {  
			if (persona[k].nome == cercato) {
				cout << "Telefono: " << persona[k].telefono << endl;
				trovato = true;
			}
		k++;
	 }

 		if (!trovato)
			cout << "nome inesistente" << endl;
 } else printf("Nessun record inserito \n");
} // RicercaDaArray

void RicercaDaFile()
{	
	dati PersTmp;
	string cercato, riga_letta;
	bool trovato = false;
	cout << "Ricerca in File "<< endl;
	cin.ignore(255,'\n'); // per evitare eventuali problemi con getline
	cout << "Inserisci il nome da cercare: ";
	getline(cin,cercato); 
	archivio.open(NOMEARCH.c_str(), ios::in); // apre il file in lettura
	if (!archivio) {
		cout << "Errore nell'apertura del file" << endl;
	} else {
			 while (getline(archivio,riga_letta) && !trovato) {
				parse(riga_letta,PersTmp);
			if (PersTmp.nome == cercato) {
				cout << "Telefono: " << PersTmp.telefono << endl;
				trovato = true;
			}
		}
		archivio.close(); // chiude il file
		if (!trovato)
			cout << "nome inesistente" << endl;
	}
} // RicercaDaFile

void  parse(string riga_letta,dati &PersTmp)
{ int i=0, j=0, ContaChar=0;
	std::size_t length;
  string strtmp;
  char buffer[50];
  char *buffered;
   
  buffered = (char*) malloc(strlen(riga_letta.c_str())*sizeof(char));
  strcpy(buffered, riga_letta.c_str());

//  cout<<"Sono in parse e riga_letta = "<<riga_letta<<"  sizeof(riga_letta)= "<<sizeof(riga_letta)<<"  strlen(riga_letta.c_str()) = "<< strlen(riga_letta.c_str())<<endl;
//  cout<<"Sono in parse e buffered = "<<buffered<<"  sizeof(buffered)= "<<sizeof(buffered)<<"  strlen(buffered) = "<< strlen(buffered)<<endl;
  if(sizeof(riga_letta)>0)
	{
		i=0;
		while (buffered[i] != '#')
			{  	
				 ContaChar++; i++; j++;
			}
		length = riga_letta.copy(buffer,ContaChar, 0);
		buffer[length]='\0';
		PersTmp.nome=buffer; 
		i++; strtmp=""; ContaChar=0; j++;
		while (i<strlen(riga_letta.c_str()) &&(riga_letta[i+1] != '0'))
			{  	
				 ContaChar++; i++;  j++; 
			}
		j=j-ContaChar;
		length = riga_letta.copy(buffer,ContaChar, j);
		buffer[length]='\0';
		PersTmp.telefono=buffer; 
	}
} // parse(string riga_letta,dati &PersTmp)

void parse_studio(string riga_letta)
{ int i=0, j=0, ContaChar=0;
	std::size_t length;
  string strtmp;
  char buffer[50];
  char *buffered;
 
  cout<<"Sono in parse_studio per iniziare la scansione "<<endl;
  
  buffered = (char*) malloc(strlen(riga_letta.c_str())*sizeof(char));
  strcpy(buffered, riga_letta.c_str());

  cout<<"Sono in parse_studio e riga_letta = "<<riga_letta<<"  sizeof(riga_letta)= "<<sizeof(riga_letta)<<"  strlen(riga_letta.c_str()) = "<< strlen(riga_letta.c_str())<<endl;
  cout<<"Sono in parse_studio e buffered = "<<buffered<<"  sizeof(buffered)= "<<sizeof(buffered)<<"  strlen(buffered) = "<< strlen(buffered)<<endl;
  if(sizeof(riga_letta)>0)
	{
		i=0;
		while (buffered[i] != '#')
			{  	strtmp[ContaChar]=buffered[i];//non memorizza niente!!
				 ContaChar++; i++; j++;
			}
		length = riga_letta.copy(buffer,ContaChar, 0);
		buffer[length]='\0';
		persona[ContaRecord].nome=buffer; 
		cout<<"Nome: "<<buffer<<"; "<<endl; 
		cout<<"Nome: "<<		persona[ContaRecord].nome<<"; "<<endl; 

	//	length =sprintf(strtmp,"%s",buffer);
 // 	strtmp[length]='\0';
		cout<<"ContaChar= "<<ContaChar<<"; i= "<<i<<"; j= "<<j<<"; strtmp = "<<strtmp<<"; buffer = "<<buffer<<endl;
		i++; strtmp=""; ContaChar=0; j++;
		while (i<strlen(riga_letta.c_str()) &&(riga_letta[i+1] != '0'))
			{  	strtmp[ContaChar]=buffered[i];//non memorizza niente!!
				 ContaChar++; i++;  j++; 
			}
		j=j-ContaChar;
		length = riga_letta.copy(buffer,ContaChar, j);
		buffer[length]='\0';
		cout<<endl<<"Num. Tel: "<<buffer<<"; "<<endl;
		persona[ContaRecord].telefono=buffer; 
		cout<<endl<<"Num. Tel: "<<persona[ContaRecord].telefono<<"; "<<endl;
		ContaRecord++;
	//	length =sprintf(strtmp,"%s",buffer);
 // 	strtmp[length]='\0';
		cout<<"ContaChar= "<<ContaChar<<"; i= "<<i<<"; j= "<<j<<"; strtmp = "<<strtmp<<"; buffer = "<<buffer<<endl;
//		cout<<strtmp;
		cout<<endl;
	}
  cout<<endl;

} // parse(string riga_letta)

void carica_dati_studio()
{	archivio.open(NOMEARCH.c_str(), ios::in); // apre il file in lettura
	if (!archivio) {
		cout << "L'archivio ancora non è stato creato file" << endl;
	} else {
			while (getline(archivio,riga_letta)) 
			{	
				cout << "  sono in carica_dati e riga_letta = "<<riga_letta; // stampa la stringa letta dal file
				cout <<"  sizeof(riga_letta)= "<<sizeof(riga_letta)<<"  strlen(riga_letta.c_str()) = "<< strlen(riga_letta.c_str())<<endl;
				cout <<"  mystrlen(riga_letta)= "<<mystrlen(riga_letta)<<endl;
				parse_studio(riga_letta); // analizza la stringa letta dal file
			}
		}
	archivio.close(); // chiude il file
} // carica_dati()  

int mystrlen(string s)
{
	int i=0;
//	while((s[i]!='0')||(s[i]))
	while(s[i+1]!='\0')
	{
		i++;
	}
	return i;
}

void parse(string riga_letta)
{ int i=0, j=0, ContaChar=0;
	std::size_t length;
  string strtmp;
  char buffer[50];
  char *buffered;

  buffered = (char*) malloc(strlen(riga_letta.c_str())*sizeof(char));
  strcpy(buffered, riga_letta.c_str());

  if(sizeof(riga_letta)>0)
	{
		i=0;
		while (buffered[i] != '#')
			{  	
				 ContaChar++; i++; j++;
			}
		length = riga_letta.copy(buffer,ContaChar, 0);
		buffer[length]='\0';
		persona[ContaRecord].nome=buffer; 
		i++; strtmp=""; ContaChar=0; j++;
		while (i<strlen(riga_letta.c_str()) &&(riga_letta[i+1] != '0'))
			{  	
				 ContaChar++; i++;  j++; 
			}
		j=j-ContaChar;
		length = riga_letta.copy(buffer,ContaChar, j);
		buffer[length]='\0';
		persona[ContaRecord].telefono=buffer; 
		ContaRecord++;
	}
} // parse(string riga_letta)

void carica_dati()
{	archivio.open(NOMEARCH.c_str(), ios::in); // apre il file in lettura
	if (!archivio) {
		cout << "L'archivio ancora non è stato creato file" << endl;
	} else {
			while (getline(archivio,riga_letta)) 
			{	
				parse(riga_letta); // analizza la stringa letta dal file
			}
		}
	archivio.close(); // chiude il file
} // carica_dati()  


void VisualizzaReport_cout()
{
  if (ContaRecord!=0){
	 cout << setiosflags(ios::left);
	cout<<setw(30)<<"StampaReport con cout"<<endl;
	cout<<setw(30)<<"Nome"<<setw(10)<<"Tel "<<endl; 
	for(int k=0; k<ContaRecord;k++)
	{  
	  cout<< setw(30)<<persona[k].nome <<"   "; 
	  cout<< setw(10)<<persona[k].telefono<<endl; 
	}

	cout<<"Numero record presenti: "<<ContaRecord<<endl<<endl;
  } else cout<<"Nessun record inserito "<<endl<<endl;
	
}

void VisualizzaReport_printf()
{
  if(ContaRecord!=0){
	  printf("%-30s \n", "StampaReport con printf");
	printf("%-30s %-10s \n","Nome","Tel "); 
	for(int k=0; k<ContaRecord;k++)
	  {  
		printf("%-30s %-10s \n", persona[k].nome.c_str(), persona[k].telefono.c_str());
	 }

	printf("Numero record presenti: %d \n\n", ContaRecord);
  } else printf("Nessun record inserito \n\n");
	
}
