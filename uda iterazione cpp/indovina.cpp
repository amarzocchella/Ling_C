#include "stdafx.h"         // libreria standard 

#include <iostream>
#include <stdlib.h>  // srand, rand 
#include <time.h>    // time 
using namespace std;
#define MAX_TENTA 7  // massimo numero tentativi 
int main()
{
  int num, conta = 0, prova;    
  cout << "\nIndovina il numero -";
  srand(time(NULL));         // inizializzo seme
  num = (rand() % 100) + 1;  // numero tra 1-100
  do{                                  
    cout << " inserisci un numero :";
    cin >> prova;
    conta++;
    if (prova < num)
      cout << "... troppo piccolo -";
    if (prova > num)
      cout << "... troppo grande  -";
  }while((num != prova) && (conta != MAX_TENTA));
  if (num == prova){
    cout << " Bravo, hai indovinato ";
    cout << " in " << conta << " tentativi!";
  }else{
    cout << " Peccato, non hai indovinato"; 
    cout << " in " << conta << " tentativi!";
    cout << "\nIl numero era " << num;
  }
}


