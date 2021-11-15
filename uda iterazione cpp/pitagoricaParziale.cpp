#include "stdafx.h"         // libreria standard 

#include <iostream>
using namespace std;
int main()
{
  int conta, numero; 
  cout << "tabellina da visualizzare : ";
  cin  >> numero;           // passo 1 
  for(conta = 1; conta <= 6; conta++){ 
    cout << conta * numero << " \t";
  }  
  system("PAUSE");
}




