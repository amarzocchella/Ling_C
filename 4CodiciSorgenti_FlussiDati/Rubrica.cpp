// Rubrica.cpp: gestione di una rubrica telefonica
// inserimento, aggiunta, visualizzazione,
// stampa e ricerca
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const string NOMEARCH = "rubrica.dat";
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
	cout << "4. Stampa rubrica" << endl;
	cout << "5. Ricerca di nomi" << endl;
	cout << "6. Fine lavoro" << endl;
// scelta dell'utente
	cout << "Scegli: ";
	cin >> s;
	cout << "--------------------------" << endl;
	return s;
} // Menu
// creazione archivio
void Crea()
{
	archivio.open(NOMEARCH.c_str(), ios::out); // apre il file per la scrittura
	cout << "Inserisci un nome (* = fine): ";
	cin >> nome;
	while (nome != "*") {
		cout << "Telefono: ";
		cin >> telefono;
		archivio << nome << " " << telefono << endl; // scrive sul file
		cout << "Inserisci un altro nome (* = fine): ";
		cin >> nome;
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
		cin >> nome;
		cout << "Telefono: ";
		cin >> telefono;
		archivio << nome << " " << telefono << endl; // scrive sul file
		archivio.close(); // chiude il file
	}
} // Aggiungi
// lettura dei dati dall'archivio
void Visualizza()
{
	archivio.open(NOMEARCH.c_str(), ios::in); // apre il file in lettura
	if (!archivio) {
		cout << "Errore nell'apertura del file" << endl;
	} else {
		archivio >> nome; // legge dal file
		while (!archivio.eof()) {
			archivio >> telefono;
			cout << nome << "; " << telefono << endl;
			archivio >> nome;
		}
		archivio.close(); // chiude il file
	}
} // Visualizza
void Stampa()
{
	ofstream stampante; // dichiara uno stream
	stampante.open("LPT1"); // apre lo stream della stampante
	archivio.open(NOMEARCH.c_str(), ios::in); // apre il file in lettura
	if (!archivio) {
		cout << "Errore nell'apertura del file" << endl;
	} else {
		cout << "Stampa in corso" << endl;
		archivio >> nome; // legge dal file
		while (!archivio.eof()) {
			archivio >> telefono;
			stampante << nome << "; " << telefono << endl;
			archivio >> nome;
		}
		archivio.close(); // chiude il file
		cout << "Stampa terminata" << endl;
	}
	stampante.close(); // chiude lo stream della stampante
} // Stampa
void Ricerca()
{
	string cercato;
	bool trovato = false;
	cout << "Inserisci il nome da cercare: ";
	cin >> cercato;
	archivio.open(NOMEARCH.c_str(), ios::in); // apre il file in lettura
	if (!archivio) {
		cout << "Errore nell'apertura del file" << endl;
	} else {
		archivio >> nome; // legge dal file
		while (!archivio.eof() && !trovato) {
			archivio >> telefono;
			if (nome == cercato) {
				cout << "Telefono: " << telefono << endl;
				trovato = true;
			}
			archivio >> nome;
		}
		archivio.close(); // chiude il file
		if (!trovato)
			cout << "nome inesistente" << endl;
	}
} // Ricerca
