// Soluzione_Simulazione_Compito_Fatture.cpp: creazione archivio Fatture
/*
Si vuole gestire un elenco le cui voci che memorizzano i seguenti dati:

Fattura: CodFattura, CodCliente, Data, Importo, Pagato. 
L’attributo Pagato avrà valori possibili: SI/NO.
Formato  Date: aaaa, mm. gg es.: “2016-05-24”

Scrivere un programma in C++ che definisca la struttura “voce”, 
composta dagli attributi elencati sopra. 
Si leggano poi da  input standard n voci, con n definito dall’utente, 
e si inseriscano in un file. 
L’utente inserisca poi il valore di un attributo del record da cercare 
e si stampi il contenuto del record, se il record è presente.
 */
 /* 
 Svolgere i seguenti compiti: 
1) Creazione del programma, comprendente: 
   la definizione delle strutture dati e le variabili necessarie 
   ad archiviare i dati in un file, le librerie necessarie, 
   il main e la chiamata, nel main, alle funzioni per la lettura dei dati 
   e per la ricerca del record. 
   Solo i Prototipi delle funzioni!!! 
   Vedi diagramma a blocchi del programma principale. (P.ti 2.5)

2.1) Implementare la funzione per la la lettura dei dati che deve 
     terminare quando l’utente lo desidera. 
     La funzione deve acquisire i dati da input standard 
     e li salva in un file. (P.ti 3.5)

2.2) Implementare la funzione per la ricerca: 
   la funzione cerca il record e se lo trova stampa il contenuto. (P.ti 4)

Attenzione: Lo svolgimento del compito senza l’uso di funzioni comporta 
           la perdita di due punti sul punteggio complessivo.
*/
/* comandi da console per compilare ed eseguire il codice:
ls
cd 4CodiciSorgenti_FlussiDati/Soluzione_Simulazione_Compito_FATTURE_C++
g++ Soluzione_Var_Globoli_Simulazione_Compito_Fatture.cpp -o Archivio_Fatture2
./Archivio_Fatture2
...
Inserisci un nome (* = fine): studenti
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
//#include <cstring>
//#define NOMEARCH = "fatture.dat";// mi darebbe errore.
using namespace std;
const string NOMEARCH = "fatture.dat";

struct Fattura{
	char CodFattura[8], CodCliente[8],
	Data[11];
   float Importo;
   int Pagato; // SI=1; NO = 2; oppure sospesa = 3;
};

Fattura fattura;
//prototipi Funzioni
int Leggi_Dati();
int Stampa_Report();// non richiesta nel compito ma la aggiungo per completezza
void Ricerca();
int main()
{
	Leggi_Dati();
	Stampa_Report();
	Ricerca();
	return 0;
}
int Leggi_Dati()
{   string Stop= "stop";
	ofstream fout;
// aggiunge altri dati
//	fout.open(NOMEARCH,  ios::out | ios::app | ios::binary); // da errore per sintassi errata di NOMEARCH 
//	fout.open("anagrafe.dat",  ios::out | ios::app | ios::binary); // Funziona anche se passo il nome file come "anagrafe.dat". 
										//apre il file binario in append se eesiste altrimenti lo crea!
	fout.open(NOMEARCH.c_str(),  ios::out | ios::app | ios::binary); // apre il file binario in append se eesiste altrimenti lo crea!
	if (!fout) {
		cout << "Errore nell'apertura dell'archivio" << endl;
	} else { 
		cout << "Codice Fattura (stop per terminare): ";
		cin >> fattura.CodFattura;
		while (fattura.CodFattura != Stop) {
			cin.ignore(80, '\n');
			cout << "Codice Cliente: ";
			cin.getline(fattura.CodCliente, 8);
			cout << "\nInserire Data (aaaa, mm. gg es.: '2022-04-08': ";
		    //getline(cin, fattura.Data); // Non questa sintassi che richiede un tipo string
			cin.getline(fattura.Data, 11);

			cout << "\nInserire Importo: ";
			cin >> fattura.Importo;

			/*cout << "\nInserire Pagato (si/no): ";
			cin >> fattura.Pagato;*/
			do {
					cout<<"\nInserire Pagato (SI=1; NO = 2; oppure sospesa = 3): ";
					cin>>fattura.Pagato;
					cout<<"\nPagato inserito = "<< fattura.Pagato<<endl;
				} while(!(fattura.Pagato==1 || fattura.Pagato ==2 ||  fattura.Pagato ==3));


			fout.write((char *) &fattura, sizeof(fattura));
			cout << "Inserisci Codice Fattura (stop per terminare): ";
			cin >> fattura.CodFattura;
		}
		fout.close();
	}
	return 0;
}


int Stampa_Report()
{
// visualizza i dipendenti registrati
	ifstream fin;
	fin.open(NOMEARCH.c_str(), ios::in | ios::binary);
	if (!fin) {
		cout << "Errore nell'apertura dell'archivio" << endl;
	} else {
		cout << "Elenco fatture registrate:" << endl;
		while (fin.read((char *) &fattura, sizeof(fattura))) {
			cout << fattura.CodFattura << ": "
			     << fattura.CodCliente << '\t'
			     << fattura.Data << '\t'
			     << fattura.Importo << " euro"<< '\t';
			   //  << fattura.Pagato << endl; // devo decodificare!!!
				switch (fattura.Pagato){
				  case 1: cout<< setw(8)<<"Si"<<endl;	 
					break;
				  case 2: cout<< setw(8)<<"NO"<<endl;	 
					break;
				  case 3: cout<< setw(8)<<"Sospesa"<<endl;	 
				   break;
			   } // fine switch
		}
		fin.close();
	}
	return 0;
}

void Ricerca() { // Funzione per cercare una voce

  string nomeDaCercare;
//  Fattura fattura;
  ifstream ilMioFile;
  
  cout << "Inserisci il campo da cercare: ";
  
  cin.ignore(80, '\n');
  getline(cin, nomeDaCercare);
  
  ilMioFile.open(NOMEARCH.c_str(), ios_base::binary); // Apro il file

   string attributo;
  cout << endl;
  while (ilMioFile.read((char *) &fattura, sizeof(fattura))) {
   attributo = (string)fattura.CodCliente;// converto il tipo char in string
  if (attributo.find(nomeDaCercare) != string::npos) { // Controllo se nella stringa codCliente è presente il campo di ricerca 

    cout << "\nTROVATO\n" << "\nCodice Cliente: " << fattura.CodCliente << "\nCodice Fattura: " << fattura.CodFattura << "\nData: " << fattura.Data << "\nImporto: " << fattura.Importo << "\nPagato: " << fattura.Pagato << endl;
    
  }
    attributo = (string)fattura.CodFattura;// converto il tipo char in string
  if (attributo.find(nomeDaCercare) != string::npos) { // Stessa cosa di prima solo con codFattura

    cout << "\nTROVATO\n" << "\nCodice Cliente: " << fattura.CodCliente << "\nCodice Fattura: " << fattura.CodFattura << "\nData: " << fattura.Data << "\nImporto: " << fattura.Importo << "\nPagato: " 
    << fattura.Pagato << endl;
    
  }
  
   attributo = (string)fattura.Data;// converto il tipo char in string
if (attributo.find(nomeDaCercare) != string::npos) {

    cout << "\nTROVATO\n" << "\nCodice Cliente: " << fattura.CodCliente << "\nCodice Fattura: " << fattura.CodFattura << "\nData: " << fattura.Data << "\nImporto: " << fattura.Importo << "\nPagato: " << fattura.Pagato << endl;
    
  }

  }

  cout << endl;

  ilMioFile.close(); // Chiudo ed esco

}

