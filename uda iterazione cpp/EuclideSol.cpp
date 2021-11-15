/* File: euclideSol.cpp */
/* Time-stamp: "2015-08-06 03:26:06 paolo" */
/* Scopo: uso del ciclo do - while         */
/* Sviluppato con: Dev-C++ 5.4.1           */
//
#include "stdafx.h"         // libreria standard 

#include <iostream>
#include <conio.h>
using namespace std;
main()
{
 /*
 Programma che calcola il MCD mediante l'algoritmo di Euclide del resto
 Questa versione: 
        verifica il corretto inserimento numero1 >=0 e chiede il reinserimento
        verifica il corretto inserimento numero2 >=0 e chiede il reinserimento
        controlla l'inserimento dei numeri negativi
        permette la ripetizione dell'algoritmo all'utente
 */
  int numero1,numero2,resto,MCD,tempo;   // definizione delle variabili
  char scelta='S';                       // definizione e inizializzazione
  cout << "\nAlgoritmo di Euclide per il calcolo del MCD.";
  do 
  {
    cout <<"\ninserisci due numeri positivi :";

    // controlla se numero1>=0 ed eventualmente chiede il reinserimento
    do
    {                                    // controllo input del numero1
      cin >> numero1;
      if (numero1<=0)
        cout << "\n il primo numero non è maggiore di 0: ripeti l'inserimento!";
    }
    while(numero1<=0);                   // ripete se numero1 <= a 0

    // controlla se numero2>=0 ed eventualmente chiede il reinserimento
    do
    {                                    // controllo input del numero1
      cin >> numero2;
      if (numero2 <= 0)
        cout <<  "\n il secondo numero non è maggiore di 0: ripeti l'inserimento!";
    }
    while(numero2<=0);                   // ripete se numero1 <= a 0

    // controlla se numero1> numero2 ed eventualmente li scambia
    if (numero2>numero1)                 // scambiali tra loro
    { 
      tempo   = numero2;
      numero2 = numero1;
      numero1 = tempo;                                 
    }

    // inizia il calcolo vero e proprio del MCD
    while(numero2>0)                     // inizio iterazione
    {
      resto   = numero1 % numero2;       // calcolo del resto
      numero1 = numero2;                 // scambio dei numeri
      numero2 = resto;
    }
    MCD=numero1;                         // assegnazione inutile, solo per chiarezza
    cout << "\n il MCD e\': " << MCD;

    // chiede all'utente l'eventuale ripetizione completa del programma
    cout << "\n vuoi effettuare una nuova elaborazione S/N? ";
    scelta = getch();                    // legge un carattere 
  }    
  while ((scelta=='S')||(scelta=='s'));  // S minuscola o s maiuscola 
    
  printf("\n\n");
}



 


