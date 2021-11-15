// dispari.cpp : definisce il punto di ingresso dell'applicazione console.
//
#include "stdafx.h"         // libreria standard 

#include <iostream>
using namespace std;
int main()
{
  int num1;                
  num1 = 0;                
  cout << "\nInserisci un numero > 2 : ";  
  cin  >> num1;
  while (num1 > 1)    // condizione di entrata  
    num1 = num1 - 2;  // corpo del ciclo  

  if (num1 == 0)      // test sul risultato
    cout << "\nil numero e' pari" << endl;
  else
    cout << "\nil numero e' dispari" << endl;
   
  system("PAUSE");
}






