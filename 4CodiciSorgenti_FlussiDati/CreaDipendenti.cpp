// CreaDip.cpp: creazione archivio dipendenti
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const string NOMEARCH = "anagrafe.dat";
int main()
{
	ofstream archivio;
	archivio.open(NOMEARCH.c_str(), ios::out | ios::binary);
	archivio.close();
	cout << "Nuovo archivio dipendenti creato" << endl;
	return 0;
}
