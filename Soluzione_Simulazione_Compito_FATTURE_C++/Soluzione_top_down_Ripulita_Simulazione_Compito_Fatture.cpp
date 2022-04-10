// Soluzione_Simulazione_Compito_Fatture.cpp: creazione archivio Fatture
// Adotteremo un approccio top-down, dall'alto al basso.
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
g++ Soluzione_top_down_Ripulita_Simulazione_Compito_Fatture.cpp -o Archivio_Fatture3
./Archivio_Fatture3
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
int Stampa_Record(Fattura fattura);
int Leggi_Dati();
void IntestazioneStamp();//prototipo
int Stampa_Report();// non richiesta nel compito ma la aggiungo per completezza
void Ricerca();
int main()
{   // 1) Osservazione: avro' bisogno di stampare/visualizzare un record estratto dal file.
  // Idea scrivo subito una funzione che svolga questo compito
  // e che verra' chiamata in altre funzioni tutte le volte che serve!	
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

int Stampa_Record(Fattura fattura)
{   
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
		IntestazioneStamp();
		while (fin.read((char *) &fattura, sizeof(fattura))) {
			Stampa_Record(fattura);
		}
		fin.close();
	}
	return 0;
}

void IntestazioneStamp(){
cout << "CodFattura: CodCliente Importo Pagato"<<endl;
}

void Ricerca() { // Funzione per cercare una voce

  string nomeDaCercare;
  ifstream ilMioFile;
  int scelta;
  
  cout << "Inserisci il campo da cercare: CodCliente 1; CodFattura 2 Data 3\n";
  cout << "esempio: 1 oppure 2  oppure  3\n";
  cin.ignore(80, '\n');
  cin >> scelta;
  cin.ignore(80, '\n');
  cout << "Inserisci il valore del campo da cercare: ";
  
  getline(cin, nomeDaCercare);
  
  ilMioFile.open(NOMEARCH.c_str(), ios_base::binary); // Apro il file

  Fattura CercaRecord(Fattura, int, string); //prototipo

   string attributo;
  cout << endl;
  while (ilMioFile.read((char *) &fattura, sizeof(fattura))) {
	    CercaRecord(fattura, scelta, nomeDaCercare);
  }

  cout << endl;

  ilMioFile.close(); // Chiudo ed esco

}

  Fattura CercaRecord(Fattura fattura, int scelta, string nomeDaCercare){ //definizione CercaRecord
	//  cout << "\nSono in CercaRecord\n";
	  string attributo= "stop";
	  
				switch (scelta){
				  case 1: attributo = (string)fattura.CodCliente;// converto il tipo char in string	 
					break;
				  case 2: attributo = (string)fattura.CodFattura;	 
					break;
				  case 3: attributo = (string)fattura.Data;	 
				   break;
			   } // fine switch
	if ((attributo != "stop") && (attributo.find(nomeDaCercare) != string::npos)) {

     cout << "\nTROVATO\n";
     IntestazioneStamp();
      Stampa_Record(fattura);
    
	}	  
  }
