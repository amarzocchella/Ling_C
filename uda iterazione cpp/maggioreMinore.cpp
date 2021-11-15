#include "stdafx.h"         // libreria standard 

#include <iostream>
using namespace std;
int main()
{
  int min, max, numero, conta;   
  for (conta = 1; conta < 7; conta++){                                  
    cout << "inserisci un numero : ";
    cin >> numero;
    if (conta==1){
      min = numero;
      max = numero;
    }  
    else   
      if (numero < min)
        min = numero; 
      else
        if (numero > max) 
          max = numero;
  }
  cout << "\n numero minore  : " << min;
  cout << "\n numero maggiore: " << max;
  system("PAUSE");
}






