/*
comandi da console
ls
cd ConteggioParole
gcc conteggio_parole_c.c -o conteggio_parole_c
./conteggio_parole_c
Ciao, come va con la programmazione, è dura, vero?

Conteggio parole e caratteri
Scrivere un programma che legge delle frasi da tastiera e le memorizza in un array di stringhe. Per ogni frase letta stampa il numero di caratteri di cui si compone e di quante parole si compone la frase.
L'immissione di frasi termina quando l'utente immette la parola stop.
A richiesta, l'utente immette un numero intero ed il programma stampa la frase che si trova in quella posizione nell'array.
Scrivere sia la versione C che C++

Frase da usare per i test non banali:
Ciao, come va con la programmazione, è dura, vero?

*/


/*
  comandi da console
ls
cd ConteggioParole
gcc conteggio_parole_c.c -o conteggio_parole_c
./conteggio_parole_c
Ciao, come va con la programmazione, e' dura, vero?
*/
#include <stdio.h>
#include <stdlib.h>

#define ph_size 1000 /* max chars per phrase */
#define wsize 20 /* max chars per parola */
char phrase [ ph_size ] ;

void stampa_word(char s1[]){
   }
  printf("; Lunghezza Parola: %d \n", LunghezzaStringa);
}//fine stampa_word

int main() {
  char c, parola [wsize];
  int i, cont  =  0 ;
 char continuare;
 
 printf ("Inserire una frase e premere invio.\n es.: Ciao, come va con la programmazione, e' dura, vero?\n");
  do {
		while (c=getchar()){ printf ("carattere immesso: %c\n", c);
		if ( 'a'<=c && c<='z' || 'A'<=c && c <='Z' ) {
//		if ( (('a'<=c) && (c<='z')) || (('A'<=c) && (c <='Z')) ) {
			if ( i<ph_size-1 && i<wsize-1 ){
				parola [ i++ ] = c ; printf ("parola = %s\n", parola);
				phrase [ i++ ] = c ;}
		} else
			if ( i ) {
					stampa_word(parola);
						phrase [ i++ ] = c ;
						cont+=i;
						i = 0 ;
					}
		}// fine while inerno
		printf ( "fine while. phrase = %s; cont = %d;\n",phrase, cont) ;

    printf("Vuoi continuare? S/N: ");
  	scanf ("%c", &continuare);
  }while (continuare =='S' || continuare =='s'); // fine while esterno
 printf("Fine programma\n");
}// fine main
