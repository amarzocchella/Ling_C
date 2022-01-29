// Eccezioni.cpp: uso di try...catch e di throw
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct TipoErrore {
	int num;
	string msg;
};
// prototipo della funzione
double MediaDaFile(string nomefile);
// funzione principale
int main()
{
	try {
		double media;
		media = MediaDaFile("numeri.txt");
		cout << "Operazione andata a buon fine: "
		     << "Media dei numeri = "
		     << media << endl;
	} catch (TipoErrore e) {
		cerr << "Errore n. " << e.num
		     << " (" << e.msg << ")" << endl;
	} catch (...) {
		cerr << "Errore indefinito" << endl;
	} // fine try
	cout << "Fine esecuzione" << endl;
	return 0;
}
double MediaDaFile(string nomefile)
{
	TipoErrore errore;
	ifstream fin(nomefile.c_str());
	if (!fin) {
		errore.num = 1;
		errore.msg = "Errore nell'apertura del file: " + nomefile;
		throw errore;
	}
	int conta = 0;
	double dato, somma=0.0;
	while (fin >> dato) {
		somma+= dato;
		conta++;
	}
	if (!conta) {
		errore.num = 2;
		errore.msg = "File " + nomefile + " vuoto";
		throw errore;
	}
	fin.close();
	double m = somma / conta;
	return m;
}
