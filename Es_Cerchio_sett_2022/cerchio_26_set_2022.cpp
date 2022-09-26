// questo è un commento
/* questo è un commento
-L’area e la circonferenza del cerchio
Il problema si pone con:
1 variabile: RAGGIO (r);
1 costante: PIG = 3.14;
il valore r dovrà essere fornito dall’utente (input).
Una terza variabile può essere usata per l’AREA (a) data dalla relazione: a = PIG* r*r; (output1).
Una quarta variabile può essere usata per la CIRC (c) data dalla relazione: c = 2*PIG*r; (output2).


 */
#include <stdio.h>   // permette di usare printf: stampa sullo schermo e scanf: legge da tastiera
#include <iostream> //permette di usare cout: stampa sullo schermo cin: legge da tastiera

// Dichiarazione variabili e Costanti:

#define PIG  3.14
double r,c,a;

using namespace std; // permette di chiamare le funzioni: cout e cin senza
//far precedere al nome della funzione il nome dello spazio dei nomi:std

int main()  { /* inizio programma */
    /* Traduciamo scrivi con printf */
    printf("Questo programma riceve il raggio in output e calcola area e circonferenza del cerchio! \n stampato con printf.\n");

/* Traduciamo scrivi con cout */
    cout<< " inserire il raggio:";
/* Traduciamo leggi con cin */
    cin>>r;

// Calcoli:
	c = 2*PIG*r;
	a = PIG* r*r;
	cout.width(5);
	cout.precision(3);
	cout<<"\n"<<" il raggio vale: "<<r<<"\n"<< " la circonferenza vale: " <<c <<"\n"<<" l'area vale: "<<a<<"\n";
	return (0);

} /* fine programma */
