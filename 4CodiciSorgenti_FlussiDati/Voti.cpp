// Voti.cpp: conta i voti raggruppati
#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <iterator>
using namespace std;
map<int, int> voti; // contenitore per il conteggio
// prototipo della funzione
void Conta(const int v);
// funzione principale
int main()
{
// dichiarazione dello stream
	ifstream fin("esiti.dat");
// iteratore per lo stream
	istream_iterator<int> ii(fin);
// iteratore per il controllo di fine file
	istream_iterator<int> eos;
// legge il file
	for_each(ii, eos, Conta);
// risultati
	map<int, int>::iterator i;
	for (i=voti.begin(); i!=voti.end(); i++)
		cout << "Voto " << i->first << ": "
		     << i->second << endl;
	return 0;
}
// funzione per il conteggio
void Conta(const int v)
{
	voti[v]++;
} // Conta
