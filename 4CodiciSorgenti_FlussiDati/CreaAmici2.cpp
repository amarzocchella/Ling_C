// CreaAmici2.cpp: apertura esplicita
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	string nome;
	ofstream fout; // dichiara lo stream
	fout.open("amici.dat"); // connette lo stream all'archivio
	cout << "inserisci i nomi" << endl;
	cout << "uno per riga (Ctrl+Z per terminare)" << endl;
	while (cin >> nome) {
		fout << nome << endl; // scrive sul file
	}
	fout.close(); // chiude il file
	return 0;
}
