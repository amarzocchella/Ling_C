#include "stdafx.h"         // libreria standard 

#include <iostream>
using namespace std;
#include <cstdlib>  // da aggiungere per le funzioni system 
#include <conio.h>  // da aggiungere per le funzioni getch()
int main()
{
  //  visualizzazione delle sequenza di Fibonacci 
  int quanti,conta,fiboA,fiboB,fiboC;
  char scelta='S';
  // prima parte: verifica dell'input "); 
  do
  {
    cout << "\nSequenza di Fibonacci";
    cout << "\ninserisci il numero di termini desiderato: ";
    do
      cin >> quanti;
    while(quanti<2);
    // seconda parte: calcolo della sequenza 
    fiboA=0;                // primo termine della sequenza
    fiboB=1;                // secondo termine della sequenza
    printf("%d ",fiboA);
    printf("%d ",fiboB);
    conta = 2;              // inizializzo il contatore termini stampati
    while(conta < quanti)
    {
      fiboC = fiboA + fiboB; // genero il nuovo termine della sequenza
      printf("%d ",fiboC);   // stampo il termine
      conta++;               // aggiorno il contatore termini stampati
      fiboA = fiboB;         // penultimo termine diventa l'ultimo 
      fiboB = fiboC;         // il nuovo termine diventa il penultimo    
    }
    cout << "\n Vuoi generare una nuova sequenza S/N ? ";
    scelta = getche();         // legge un carattere e lo visualizza 
    system("cls");
  }    
  while ((scelta=='S')||(scelta=='s'));   // S minuscola o s maiuscola 
}


