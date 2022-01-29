// LeggiAmici4.cpp: lettura archivio 
// (utilizza il metodo eof() per il controllo di fine file)
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	ifstream fin("amici.dat"); // apre il file in lettura
	string nome;
	fin >> nome; // legge dal file
	while (!fin.eof()) {
		cout << nome << endl;
		fin >> nome;
	}
	fin.close(); // chiude il file
	return 0;
}
