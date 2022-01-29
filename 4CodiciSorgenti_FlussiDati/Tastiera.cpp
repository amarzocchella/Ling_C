// Tastiera.cpp: acquisizione di caratteri
#include <iostream>
using namespace std;
int main()
{
	char codice[5],nome[40],telefono[24];
// acquisizione dei dati
	cout << "Inserimento nuovo cliente " << endl;
	cout << "------------------------- " << endl;
	cout << "Codice cliente: ";
	cin >> codice;
	cin.ignore(80,'\n');
	cout << "Nome Societa': ";
	cin.getline(nome,40);
	cout << "Telefono: ";
	cin >> telefono;
	cin.ignore(80,'\n');
// visualizza
	cout << codice << endl;
	cout << nome << endl;
	cout << telefono << endl;
	cout << endl;
// attesa
	cout << "premi Invio per continuare" << endl;
	cin.get();
}
