#include "stdafx.h"         // libreria standard 

#include <iostream>
using namespace std;
int main()
{
  int entrate=0, uscite=0, importo;   
    do{                                  
    cout << " inserisci un importo :";
    cin >> importo;
    if (importo < 0 )
		uscite = uscite + importo;
	else
		entrate = entrate + importo;
   }while(importo != 0); 
    cout << " Entrate= " << entrate;
    cout << " Uscite = " << uscite;
    cout << " Saldo  = " << entrate+uscite;
 }




