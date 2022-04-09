/*   
 * "programma spesa Justin", 
  sviluppato con Record e funzioni e menu.

 * Per ogni prodotto memorizza:
 *  
 * DescrizioneProdotto, Prezzo, Quantità, AliquotaIVA
 * 
 * Alla fine, per ogni prodotto stampa:
 * 
 * DescrizioneProdotto, Prezzo, Quantità, AliquotaIVA, Importo (cioè prezzo + IVA)
 *
 */ 
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

string nome="Test Menu";
const string NOMEARCH = "anagrafe.dat";



struct Persona {
	int ID; // identificativo intero va bene int se non inizia con zero altrimenti occorre array di char.
	char nome[50]; // cognome e nome
	double stipendio; // stipendio
};
Persona dipendente;

//prototipi Funzioni
string minuscolo(string s);
int Menu();
void Crea();
void Aggiungi();
void Visualizza();
void Stampa();
void Ricerca();
void VisualizzaReport_cout();
void VisualizzaReport_printf();

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
	cout << "Esempio programma con menu" << endl;
	cout << "1. Creazione archivio" << endl;
	cout << "2. Aggiunta nuove voci" << endl;
	cout << "3. Visualizzazione Elenco" << endl;
	cout << "4. Stampa Elenco" << endl;
	cout << "5. Ricerca di voci" << endl;
	cout << "6. Fine lavoro" << endl;
// scelta dell'utente
	cout << "Scegli: ";
	cin >> s;
	cout << "--------------------------" << endl;
	return s;
} // Menu
// creazione archivio

// Definiamo Le funzioni

string minuscolo(string s)
{
	for (unsigned i = 0; i < s.size(); ++i)
		s[i] = tolower(s[i]);
	return s;
}

void Crea()
{	
	ofstream archivio;
	archivio.open(NOMEARCH.c_str(), ios::out | ios::binary);
	archivio.close();
	cout << "Nuovo archivio dipendenti creato" << endl;
}// Crea
// aggiunta di dati all'archivio
void Aggiungi()
{ 	ofstream fout;
// aggiunge altri dati
	fout.open("anagrafe.dat", ios::app | ios::binary);
	if (!fout) {
		cout << "Errore nell'apertura dell'archivio" << endl;
	} else {
		cout << "Matricola del dipendente (0 = fine): ";
		cin >> dipendente.ID;
		while (dipendente.ID != 0) {
			cin.ignore(80, '\n');
			cout << "Cognome e nome del dipendente: ";
			cin.getline(dipendente.nome, 50);
			cout << "Stipendio (euro): ";
			cin >> dipendente.stipendio;
			fout.write((char *) &dipendente, sizeof(dipendente));
			cout << "Inserisci un'altra matricola (0 = fine): ";
			cin >> dipendente.ID;
		}
		fout.close();
	}
} // Aggiungi
// lettura dei dati dall'archivio


void Visualizza()
{
// visualizza i dipendenti registrati
	ifstream fin;
	fin.open("anagrafe.dat", ios::in | ios::binary);
	if (!fin) {
		cout << "Errore nell'apertura dell'archivio" << endl;
	} else {
		cout << "Elenco dipendenti registrati:" << endl;
		while (fin.read((char *) &dipendente, sizeof(dipendente))) {
			cout << dipendente.ID << ": "
			     << dipendente.nome << '\t'
			     << dipendente.stipendio << " euro"
			     << endl;
		}
		fin.close();
	}
}

void Stampa()
{
	 printf("%50s \n\n", "Stampa in due modalità  ");
			VisualizzaReport_cout();
			VisualizzaReport_printf();

} // Stampa

void Ricerca()
{
			cout << "Sei in Ricerca: nome="<<  nome << "; "  << endl;
} // Ricerca

void VisualizzaReport_cout()
{

	cout << "Implementa tu questa funzione aiutandoti con esempi già visti "<< endl;
	cout << "vedi Masera_Media_alunni_con_menu.cpp vedi "<< endl;
	// Implementa tu questa funzione aiutandoti con esempi già visti.
	
}

void VisualizzaReport_printf()
{
	printf("%-50s \n", "Implementa tu questa funzione aiutandoti con esempi già visti");
	printf("%-50s \n", "vedi Masera_Media_alunni_con_menu.cpp vedi");
	/* Implementa tu questa funzione aiutandoti con esempi già visti.
		*/	
}
