
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;
const string NOMEARCH = "fatture.dat";
fstream archivio; // dichiara stream

struct Fattura{
	char CodFattura[8], CodCliente[8],
	Data[11];
   float Importo;
   int Pagato; // SI=1; NO = 2; oppure sospesa = 3;
};

Fattura fattura;
//prototipi Funzioni
int Leggi_Dati();
void Ricerca();
int Stampa_Report();// non richiesta nel compito ma la aggiungo per completezza
void IntestazioneStamp();//prototipo
int Stampa_Record(Fattura fattura);
int ApriFout();// apre il file per scrivere nel file
int ApriFin(); // apre il file per leggere dal file

int main()
{
	Leggi_Dati();
	Stampa_Report();
	Ricerca();
	return 0;
}

int ApriFout(){// apre il file per scrivere nel file
	archivio.open(NOMEARCH.c_str(),  ios::out | ios::app | ios::binary); // apre il file binario in append se eesiste altrimenti lo crea!
	if (!archivio) {
		cout << "Errore nell'apertura dell'archivio" << endl;
		return 0; // se va male ritorna zero
	} else {
	return 1; // se tutto va bene ritorna un valore intero maggiore di zero
	}
}
int ApriFin(){ // apre il file per leggere dal file
	archivio.open(NOMEARCH.c_str(), ios::in | ios::binary);
	if (!archivio) {
		cout << "Errore nell'apertura dell'archivio" << endl;
		return 0; // se va male ritorna zero
	} else {
	return 1; // se tutto va bene ritorna un valore intero maggiore di zero
	}
}

int Leggi_Dati()
{   string Stop= "stop";
	if (ApriFout())
	 { cout << "Codice Fattura (stop per terminare): ";
		cin >> fattura.CodFattura;
		while (fattura.CodFattura != Stop) {
			cin.ignore(80, '\n');
			cout << "Codice Cliente: ";
			cin.getline(fattura.CodCliente, 8);
			cout << "\nInserire Data (aaaa, mm. gg es.: '2022-04-08': ";
			cin.getline(fattura.Data, 11);

			cout << "\nInserire Importo: ";
			cin >> fattura.Importo;

			do {
					cout<<"\nInserire Pagato (SI=1; NO = 2; oppure sospesa = 3): ";
					cin>>fattura.Pagato;
					cout<<"\nPagato inserito = "<< fattura.Pagato<<endl;
				} while(!(fattura.Pagato==1 || fattura.Pagato ==2 ||  fattura.Pagato ==3));


			archivio.write((char *) &fattura, sizeof(fattura));
			cout << "Inserisci Codice Fattura (stop per terminare): ";
			cin >> fattura.CodFattura;
		}
		archivio.close();
	}
	return 0;
}

int Stampa_Record(Fattura fattura)
{   
			cout << fattura.CodFattura << ": "
			     << fattura.CodCliente << '\t'
			     << fattura.Data << '\t'
			     << fattura.Importo << " euro"<< '\t';
				switch (fattura.Pagato){ // devo decodificare!!!
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
	if (ApriFin()) {
		cout << "Elenco fatture registrate:" << endl;
		IntestazioneStamp();
		while (archivio.read((char *) &fattura, sizeof(fattura))) {
			Stampa_Record(fattura);
		}
		archivio.close();
	}
	return 0;
}

void IntestazioneStamp(){
cout << "CodFattura: CodCliente Importo Pagato"<<endl;
}

void Ricerca() { // Funzione per cercare una voce

  string nomeDaCercare;
  int scelta;
  
  cout << "Inserisci il campo da cercare: CodCliente 1; CodFattura 2 Data 3\n";
  cout << "esempio: 1 oppure 2  oppure  3\n";
  cin.ignore(80, '\n');
  cin >> scelta;
  cin.ignore(80, '\n');
  cout << "Inserisci il valore del campo da cercare: ";
  
  getline(cin, nomeDaCercare);
  
  if (ApriFin())
	{	Fattura CercaRecord(Fattura, int, string); //prototipo
		string attributo;
		cout << endl;
		while (archivio.read((char *) &fattura, sizeof(fattura))) {
				CercaRecord(fattura, scelta, nomeDaCercare);
		}

  cout << endl;

  archivio.close(); // Chiudo ed esco
  }
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
