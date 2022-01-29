// Colori.cpp: uso di stream iterator (scrittura)
#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
using namespace std;
int main()
{
	string nc;
// dichiarazione dello stream
	ofstream fout("tavolozza.txt");
// iteratore per lo stream di output
	ostream_iterator<string> oo(fout,"\n") ;
	cout << "Nome del colore (* = fine): ";
	cin >> nc;
	while (nc != "*") {
		*oo = nc;
		oo++;
		cout << "Altro colore (* = fine): ";
		cin >> nc;
	}
	return 0;
}
