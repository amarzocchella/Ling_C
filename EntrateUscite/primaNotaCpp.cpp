/*
 *  comandi per test da console 
 * ls
 * cd EntrateUscite
 * EntrateUscite g++ -Wall -g primaNotaCpp.cpp -o primaNotaCpp
 * EntrateUscite ./primaNotaCpp


PROBLEMA SVOLTO PASSO PASSO 
✔Il problema
Scriviamo un programma che calcola il saldo di cassa relativo 
a una serie di importi inseriti ciclicamente  da  un  utente:  
l’inserimento  termina  quando  viene  digitato  il  numero  0,  
che  ha  lafunzione di tappo della sequenza.
✔L’analisi e la definizione della strategia
Per il calcolo del saldo è necessario fare la differenza 
tra la sommatoria accumulata nella variabile 
delle uscitee la sommatoria accumulata nella variabile delle entrate. 
Il programma si compone di un ciclo a controllo finale, all’interno 
del quale vengono sommati gli importi inseriti 
in due variabili accumulatore, 
chiamate rispettivamente entrate e uscite, 
a secondase l’importo è positivo o negativo. 
Se il dato inserito è uguale a 0, 
l’iterazione termina, 
viene calcolatoil saldo e si visualizzano i tre valori all’utente 
entrate, uscite, saldo.
✔La pseudocodifica e l’algoritmo risolutivo
La pseudocodifica e il flow-chart 
sono riportati di seguito (vedi libro pag 104).
 I affinamento
  • fai
    – leggi un numero e aggiorna i dati
  • mentre il numero inserito <> 0
 
 II affinamento
  • fai
    – leggi un numero
    – se > 0
    – aggiorna entrate
    – altrimenti 
    – aggiorna uscite
  • mentre il numero inserito <> 0
  • comunica i valori e il saldo
 
 III affinamento – pseudocodifica da cui e' stato ricavato il Flow-Chart:
  
  inizio
   fai
    leggi(importo)
    se(importo<0)
     allora
      uscite <-- uscite+importo
     altrimenti
      entrate <-- entrate+importo
     fineSe
  mentre (importo<>0)
  scrivi(entrate)
  scrivi(uscite)
  scrivi(entrate+uscite)
  
  fine
*/

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

/* test
~/LingC$ g++ -Wall -g primaNotaCpp.cpp -o primaNotaCpp
~/LingC$ ./primaNotaC_c
 inserisci un importo :3
 inserisci un importo :4
 inserisci un importo :5
 inserisci un importo :-6
 inserisci un importo :0
 Entrate= 12 Uscite = -6 Saldo  = 6 
~/LingC$ 
 */

