// Stampa.cpp: stampa archivio su carta
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	ifstream fin; // stream per il file
	ofstream stampante; // stream per la stampante
	fin.open("amici.dat"); // apre il file in lettura
	stampante.open("LPT1"); // apre lo stream della stampante
	string nome;
	while (fin >> nome) { // legge dal file
		stampante << nome << endl;
	}
	fin.close(); // chiude il file
	return 0;
}
