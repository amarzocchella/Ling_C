// Eccezioni2.cpp: uso di exceptions
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main ()
{
	string dato;
	ifstream archivio;
	archivio.exceptions (ifstream::eofbit | ifstream::failbit | ifstream::badbit);
	try {
		archivio.open ("righe.txt");
		while (archivio >> dato)
			cout << dato << endl;
		archivio.close();
	} catch (ifstream::failure e) {
		cout << "Errore di I/O sull'archivio: "
		     << e.what() << endl;
	}
	
	return 0;
}
