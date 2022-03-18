// Rubrica.cpp: gestione di una rubrica telefonica
// inserimento, aggiunta, visualizzazione,
// stampa e ricerca
/* comandi da console per compilare ed eseguire il codice:
ls
cd 4CodiciSorgenti_FlussiDati
g++ Rubrica_getline.cpp -o Rubrica
./Rubrica
...
Inserisci un nome (* = fine): studenti
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

const string NOMEARCH = "rubrica_getline.dat";
fstream archivio; // dichiara stream
string nome, telefono;
// prototipi delle funzioni
int Menu();
void Crea();
void Aggiungi();
void Visualizza();
void Stampa();
void Ricerca();
// funzione principale
int main ()
{
	int scelta;
	do {
		scelta = Menu();
		switch (scelta) {
		case 1:
			Crea();
			break;
		case 2:
			Aggiungi();
			break;
		case 3:
			Visualizza();
			break;
		case 4:
			Stampa();
			break;
		case 5:
			Ricerca();
			break;
		case 6:
			cout << "fine lavoro" << endl;
			break;
		}
	} while (scelta!=6);
	return 0;
}
// menu delle scelte
int Menu()
{
	int s;
	cout << "--------------------------" << endl;
	cout << "Gestione rubrica telefonica" << endl;
	cout << "1. Creazione rubrica" << endl;
	cout << "2. Aggiunta nuovi nomi" << endl;
	cout << "3. Visualizzazione rubrica" << endl;
	cout << "4. Stampa rubrica (Attenzione stampa in LPT1)" << endl;
	cout << "5. Ricerca di nomi" << endl;
	cout << "6. Fine lavoro" << endl;
// scelta dell'utente
	cout << "Scegli: ";
	cin >> s;
	cin.ignore(255,'\n'); // togliamo invio dal buffer per evitare eventuali problemi con getline
	cout << "--------------------------" << endl;
	return s;
} // Menu
// creazione archivio
void Crea()
{
	archivio.open(NOMEARCH.c_str(), ios::out); // apre il file per la scrittura e se il file esiste lo sovrascrive!!!
	cout << "Inserisci un nome (* = fine): ";
	//		cin >> nome;
    getline (cin,nome);
	while (nome != "*") {
		cout << "Telefono: ";
		cin >> telefono;
		archivio << nome << " " << telefono << endl; // scrive sul file
		cout << "Inserisci un altro nome (* = fine): ";
    // attenzione prende solo un nome senza spazi
    // meglio usare la getline
    //lascio allo studente le opportune modifiche.
	//	cin >> nome;
	cin.ignore(255,'\n'); // togliamo invio dal buffer per evitare eventuali problemi con getline
    getline (cin,nome);
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
	//		cin >> nome;
   getline (cin,nome);
  	cout << "Telefono: ";
		cin >> telefono;
		archivio << nome << " " << telefono << endl; // scrive sul file
		archivio.close(); // chiude il file
	}
} // Aggiungi
// lettura dei dati dall'archivio
void Visualizza()
{ string stLine;
	archivio.open(NOMEARCH.c_str(), ios::in); // apre il file in lettura
	if (!archivio) {
		cout << "Errore nell'apertura del file" << endl;
	} else {
	//	archivio >> nome; // legge dal file
		while (!archivio.eof()) {
			//archivio >> telefono;
			//cout << endl<< nome << "; " << telefono << endl;
			//archivio >> nome;
			getline (archivio, stLine);
			cout << endl<< stLine << "; " <<  endl;
		}
		archivio.close(); // chiude il file
	}
} // Visualizza
void Stampa()
{ string stLine;
	ofstream stampante; // dichiara uno stream
	stampante.open("LPT1"); // apre lo stream della stampante
	archivio.open(NOMEARCH.c_str(), ios::in); // apre il file in lettura
	if (!archivio) {
		cout << "Errore nell'apertura del file" << endl;
	} else {
		cout << "Stampa in corso" << endl;
	//	archivio >> nome; // legge dal file
		while (!archivio.eof()) {
		//	archivio >> telefono;
		//	stampante << nome << "; " << telefono << endl;
		//	archivio >> nome;
			getline (archivio, stLine);
			stampante << stLine << "; " << endl;
		}
		archivio.close(); // chiude il file
		cout << "Stampa terminata" << endl;
	}
	stampante.close(); // chiude lo stream della stampante
} // Stampa
void Ricerca()
{
	string cercato, stLine;
	bool trovato = false;
	cout << "Inserisci il nome da cercare: ";
	//cin >> cercato;
    getline (cin,cercato);
    cout<<"cercato ="<<cercato<<"  lunghezza ="<<cercato.length()<<endl;
	archivio.open(NOMEARCH.c_str(), ios::in); // apre il file in lettura
	if (!archivio) {
		cout << "Errore nell'apertura del file" << endl;
	} else {
//		archivio >> nome; // legge dal file
		getline (archivio, stLine);
		while (!archivio.eof() && !trovato) {
		//	archivio >> telefono;
		//	if (nome == cercato) {
		//	if (strcasecmp(stLine.c_str(), cercato.c_str()) == 0) {// le due stringhedevono essere uguali.
			if (strncasecmp(stLine.c_str(), cercato.c_str(), cercato.length()) == 0) {// ecco come fare a confrontare solo fino a prima che inizi il telefono 
			//	cout << "Telefono: " << telefono << endl;
				cout << stLine << "; " << endl;
				trovato = true;
			}
	//		archivio >> nome;
			cout<<"Sono in Ricerca! e stLine ="<<stLine<<endl;
			getline (archivio, stLine);
		}
		archivio.close(); // chiude il file
		if (!trovato)
			cout << "nome inesistente" << endl;
	}
} // Ricerca
