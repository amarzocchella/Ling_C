#include "stdafx.h"         // libreria standard 

#include <iostream>
using namespace std;
int main()
{
  int x, inizio, fine, passo;
  cout << "valore iniziale: ";
  cin  >> inizio;
  cout << "valore finale  : ";
  cin  >> fine;
  cout << "passo (step)   : ";
  cin  >> passo;
  // iterazione determinata FOR
  for(x = inizio; x <= fine; x = x + passo)              
    cout << "ciaoF \t";
  cout << endl;
  // iterazione indeterminata WHILE 
  x = inizio;
  while (x <= fine){
    x = x + passo;              
    cout << "ciaoW \t";
   };
  }

  
  
