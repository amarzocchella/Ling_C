// cerchio_con_fz_Array.cpp
/* 
 
 vedi https://www.cplusplus.com/reference/cstdlib/rand/
 
int rand (void);
Generate random number
Returns a pseudo-random integral number in the range between 0 and RAND_MAX.

This number is generated by an algorithm that returns a sequence of apparently non-related numbers each time it is called. This algorithm uses a seed to generate the series, which should be initialized to some distinctive value using function srand.

RAND_MAX is a constant defined in <cstdlib>.

A typical way to generate trivial pseudo-random numbers in a determined range using rand is to use the modulo of the returned value by the range span and add the initial value of the range:

v1 = rand() % 100;         // v1 in the range 0 to 99
v2 = rand() % 100 + 1;     // v2 in the range 1 to 100
v3 = rand() % 30 + 1985;   // v3 in the range 1985-2014 


Notice though that this modulo operation does not generate uniformly distributed random numbers in the span (since in most cases this operation makes lower numbers slightly more likely).

C++ supports a wide range of powerful tools to generate random and pseudo-random numbers (see <random> for more info).

*/
#include <iostream>
#include <cstdlib>

#define PIG 3.14
// oppure
const float PGreco = 3.14;

// Dichiarazioni var globali
float ArrayDiRaggi[]={3.0,3.5,4.0,4.5};

// Prototipi funzioni
void calcola (float &, float &, float &);
void stampa (float &, float &, float &);
void LeggiRaggioDaArray(int ,float [], float &);

/*using namespace std; serve in C++ per accedere a cin e cout senza dovere 
						utilizzare std::cin >>...; o std::cout <<...;*/
using namespace std; 

int main (void) {
 // codice funzione principale
 //Dichiarazioni variabili locali al main
 float r=0,c=0,a=0;
 char continuare;

     int dim = sizeof(ArrayDiRaggi) / sizeof(ArrayDiRaggi[0]);

	printf("Vuoi fare i calcoli con raggio Random? S/N: ");
	scanf ("%c", &continuare);
    while (continuare =='S' || continuare =='s') {
		LeggiRaggioDaArray(dim, ArrayDiRaggi, r);
		calcola (r, c, a);
		stampa (r, c, a);

		getchar();/*serve ad elimunare il simbolo di invio dal buffer 
					di lettura, residuo della lettura al passo 
					precedente. */
		printf("Vuoi continuare con raggio Random? S/N: ");
		scanf ("%c", &continuare);
	} //fine while

do { // chiediamo all'utente cio' che ci serve per i l'elaborazione
		printf("Inserire il raggio e premere invio: ");
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

void LeggiRaggioDaArray(int dim,float ArrayRaggi[], float &r){ 
	int indice = 0;
	printf ("Dimensione ArrayRaggi: %i;\n", dim);
	for (int i = 0; i< dim; i++) {
		printf ("ArrayRaggi[ %d] =%5.2f;\n", i, ArrayRaggi[i]);
		
	}
	indice = rand() % dim;
	printf ("indice rand: %i; ArrayRaggi[%i] = %5.2f\n", indice,indice,ArrayRaggi[indice]);
	r = ArrayRaggi[indice];
}

/*
L'output è
Vuoi fare i calcoli con raggio Random ? S/N: s
Dimensione ArrayRaggi: 4;
ArrayRaggi[ 0] = 3.00;
ArrayRaggi[ 1] = 3.50;
ArrayRaggi[ 2] = 4.00;
ArrayRaggi[ 3] = 4.50;
indice rand: 1; ArrayRaggi[1] = 0
Il raggio vale:  3.50;
La circonferenza vale: 21.98;
L'area del cerchio vale: 38.47;
Inserire il raggio:
Inserire il raggio: 3
Il raggio vale:  3.00;
La circonferenza vale: 18.84;
L'area del cerchio vale: 28.26;
Vuoi continuare ? S/N: s
Inserire il raggio:
*/
