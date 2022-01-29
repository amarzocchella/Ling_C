// LeggiAmici.cpp: lettura archivio
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	string nome;
	ifstream fin("amici.dat"); // apre il file in lettura
	while (fin >> nome) { // legge dal file fino alla fine
		cout << nome << endl;
	}
	fin.close(); // chiude il file
	return 0;
}
