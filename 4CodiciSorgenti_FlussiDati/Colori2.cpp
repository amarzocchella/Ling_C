// Colori2.cpp: legge i colori, ordina e scrive su file ordinato
// usa iteratori per gli stream, vector e algoritmi standard
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
int main()
{
// dichiarazione degli stream
	ifstream fin("tavolozza.txt"); // input
	ofstream fout("ordinati.txt"); // output
// iteratori per gli stream
	istream_iterator<string> ii(fin); // input
	ostream_iterator<string> oo(fout, "\n"); // output
// iteratore per il controllo di fine file
	istream_iterator<string> eos;
// vettore per i colori
	vector<string> c(ii, eos);
	sort(c.begin(), c.end()); // ordina
	copy(c.begin(), c.end(), oo); // copia su stream di output
	return 0;
}
