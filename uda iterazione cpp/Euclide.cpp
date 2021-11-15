// dispari.cpp : definisce il punto di ingresso dell'applicazione console.
//
#include "stdafx.h"         // libreria standard 

#include <iostream>
using namespace std;
main()
{
  int num1, num2, resto;
    cout <<"\ninserisci due numeri positivi :" << endl;
    cin >> num1;
    cin >> num2;
    while(num2 > 0)             
    {
      resto = num1 % num2;  // calcolo del resto
      num1  = num2;         // scambio dei numeri
      num2  = resto;
    }
    cout << "\n il MCD e\': " << num1; 
}

 



