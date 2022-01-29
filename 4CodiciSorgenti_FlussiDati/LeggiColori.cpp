// LeggiColori.cpp: uso di stream iterator (lettura)
#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
using namespace std;
int main()
{
// dichiarazione dello stream
	ifstream fin("tavolozza.txt");
// iteratore per lo stream di input
	istream_iterator<string> ii(fin) ;
// iteratore per il controllo di fine file
	istream_iterator<string> eos;
	while (ii != eos) {
		cout << *ii << endl;
		++ii;
	}
	return 0;
}
