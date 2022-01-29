// InserDip.cpp: inserimento dipendenti
#include <iostream>
#include <fstream>
using namespace std;
struct Persona {
	int ID; // matricola
	char nome[50]; // cognome e nome
	double stipendio; // stipendio
};
Persona dipendente;
int main()
{
	ofstream fout;
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
	return 0;
}
