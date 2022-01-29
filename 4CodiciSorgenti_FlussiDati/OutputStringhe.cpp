// OutputStringhe.cpp: operatore << per l’output di una stringa
#include <iostream>
#include <cstring>
using namespace std;

class Stringa
{
	char s[30];
public:
// metodi
	Stringa operator= (const char* sorgente);
	friend bool operator== (Stringa&, Stringa&);
	friend ostream& operator<< (ostream&, Stringa&);
};

Stringa Stringa::operator= (const char *sorgente)
{
strcpy(s, sorgente);
return *this;
}
ostream& operator<< (ostream& os, Stringa& a)
{
	os << a.s;
	return os;
}
// funzione principale
int main()
{
	Stringa s1, s2; // istanze della classe
	s1 = "Milano";
	s2 = "Roma";
	cout << s1;
	cout << endl;
	cout << s2;
	cout << endl;
	cout << s1 << ' ' << s2 << endl;
	return 0;
}
