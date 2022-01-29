// AggiungiAmici.cpp: aggiunta di nuovi nomi
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	string nome;
// apre il file in append
	ofstream fout("amici.dat", ios::app);
	cout << "inserisci nuovi nomi" << endl;
	cout << "uno per riga (Ctrl+Z per terminare)" << endl;
	while (cin >> nome) {
		fout << nome << endl; // scrive sul file
	}
	fout.close(); // chiude il file
	return 0;
}
