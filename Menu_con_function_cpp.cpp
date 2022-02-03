// Menu_con_function.cpp: Struttura di un menu
// inserimento, aggiunta, visualizzazione,
// stampa e ricerca
// comandi da Console:
//ls
//comando compilazione da Console: $ g++ Menu_con_function.cpp -o Menu_con_function_cpp
// comando lancio da Console: ./Menu_con_function_cpp


#include <iostream>
using namespace std;

// prototipi delle funzioni
int Menu();
void Crea();
void Aggiungi();
void Elimina();
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
			Elimina();
			break;
		case 4:
			Visualizza();
			break;
		case 5:
			Stampa();
			break;
		case 6:
			Ricerca();
			break;
		case 7:
			cout << "fine lavoro" << endl;
			break;
		}
	} while (scelta!=7);
	return 0;
}
// menu delle scelte
int Menu()
{
	int s;
	cout << "--------------------------" << endl;
	cout << "Gestione elenco voci" << endl;
	cout << "1. Creazione elenco" << endl;
	cout << "2. Aggiunta nuove voci" << endl;
	cout << "3. Elimina voce" << endl;
	cout << "4. Visualizzazione elenco" << endl;
	cout << "5. Stampa elenco" << endl;
	cout << "6. Ricerca di una voce" << endl;
	cout << "7. Fine lavoro" << endl;
// scelta dell'utente
	cout << "Scegli: ";
	cin >> s;
	cout << "--------------------------" << endl;
	return s;
} // Menu
// creazione archivio
void Crea()
{
	cout << "Sei in Crea";
} // Crea
// aggiunta di dati all'archivio
void Aggiungi()
{

	cout << "Sei in Aggiungi()"<< endl;
} // Aggiungi
// Elimina dati all'archivio
void Elimina()
{

	cout << "Sei in Elimina()"<< endl;
} // Elimina
// lettura dei dati dall'archivio
void Visualizza()
{
	cout << "Sei in Visualizza()"<< endl;
} // Visualizza
void Stampa()
{
	cout << "Sei in Stampa()"<< endl;
} // Stampa
void Ricerca()
{
	cout << "Sei in Ricerca()"<< endl;
} // Ricerca
