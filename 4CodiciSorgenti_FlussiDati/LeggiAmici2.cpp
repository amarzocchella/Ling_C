// LeggiAmici2.cpp: lettura archivio con controllo degli errori
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
string nome;
ifstream fin("amici.dat"); // apre il file in lettura
if (!fin) {
cout << "Errore nell'apertura del file" << endl;
}
else {
while (fin >> nome) { // legge dal file
cout << nome << endl;
}
fin.close(); // chiude il file
}
return 0;
}