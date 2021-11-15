//* File: pitagora2Sol.cpp */
/* Time-stamp: "2014-09-06 03:26:06 paolo" */
/* Scopo: uso di cicli for annidati        */
/* Sviluppato con: Dev-C++ 5.4.1           */
#include <iostream>
using namespace std;
main()
{
//dichiarazione variabile di conteggio dei due cicli
  int riga,colonna,tabellina; 

// ciclo di acquisizione dati
  do                                      //ciclo di controllo sull'inserimento tabellina
  {                                       //compresa tra 1 e 20
    cout << "inserisci la tabellina da visualizzare?";
    cin  >> tabellina;
  }while ((tabellina<1)||(tabellina>20));

// cicli di elaborazione
  for(riga=1;riga<=tabellina;riga++)               //ciclo esterno per le righe
  { 
    cout << "\n";                                  //posizionamento su di una nuova riga
    for(colonna=1;colonna<=tabellina;colonna++)    //ciclo interno
      cout << " \t" << riga*colonna;                //stampa riga*colonna e spostamento su di nuova tabulazione
  }    
  
  printf("\n\n");
}
