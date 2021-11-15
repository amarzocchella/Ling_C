#include "stdafx.h"         // libreria standard 
#include <iostream>
using namespace std;
int main()
{
  int tanti, prove = 0;
  do                 // ciclo di controllo input
  {                  // compreso tra 1 e 10
    cout << "Inserisci un numero 1 < N < 10: ";
    cin  >> tanti;
    prove= prove + 1;
  }while ((tanti < 1)||(tanti > 10));
 
  cout << "\nNumero OK dopo " << prove << " prove";
}



