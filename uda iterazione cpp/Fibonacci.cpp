#include "stdafx.h"         // libreria standard 

#include <iostream>
using namespace std;
int main()
{
  int num1, conta, fibA, fibB, fibC;
  fibA = 1;         // primo termine 
  fibB = 1;         // secondo termine 
  conta = 2 ;         
  cout << "\ninserisci il numero di termini: ";
  cin >> num1;
  cout << "1, 1 ";  // stampo primi 2 termini
  while(conta < num1)
  {
    fibC = fibA + fibB;    
    cout << ", " << fibC;
    conta++;         // aggiorno il contatore 
    fibA = fibB;     // ultimo diventa penultimo 
    fibB = fibC;     // il nuovo diventa ultimo    
  }
  system("PAUSE");
}  




