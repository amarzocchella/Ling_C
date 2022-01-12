// cerchio_con_fz.cpp
#include <iostream>


#define PIG 3.14
// oppure
const float PGreco = 3.14;


// Prototipi funzioni
void calcola (float &, float &, float &);
void stampa (float &, float &, float &);
/*using namespace std; serve in C++ per accedere a cin e cout senza dovere 
						utilizzare std::cin >>...; o std::cout <<...;*/
using namespace std; 

int main (void) {
 // codice funzione principale
 //Dichiarazioni variabili locali al main
 float r=0,c=0,a=0;
 char continuare;
 do { // chiediamo all'utente cio' che ci serve per i l'elaborazione
		printf("Inserire il raggio e premere invio");
		scanf("%f", &r);
		calcola (r, c, a);
		stampa (r, c, a);
		printf("Vuoi continuare? S/N: ");
		getchar();/*serve ad elimunare il simbolo di invio dal buffer 
					di lettura, residuo della lettura del raggio al passo 
					precedente. */
		scanf("%c", &continuare);		
 } while((continuare =='S')||(continuare =='s'));
 
}

void calcola (float &r, float &c, float &a){
 // codice funzione calcola
	c = 2 * PIG * r ;
	a = PIG * r * r;
}

void stampa (float &r, float &c, float &a){
 // codice funzione stampa
	printf("Il raggio vale: %5.2f; \n ", r);
	printf("La circonferenza vale: %5.2f; \n ", c);
	printf("L'area del cerchio vale: %5.2f; \n ", a);
}
