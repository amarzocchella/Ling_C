// cerchio_fz.c
// #include <iostream> // in C++
#include <stdio.h>
#include <stdlib.h>

#define PIG 3.14
// oppure
const float PGreco = 3.14;

/*using namespace std; serve in C++ per accedere a cin e cout senza dover utilizzare std::cin >>...; o std::cout <<...;*/

//prototipi funzioni
void calcola (float *,float *, float *);
void stampa (float *,float *, float *);

int main (void){
	float r=0, c=0,a=0;
	char continuare;
do {
	// chiediamo i dati all'utente
		printf("Inserire il raggio: ");
		scanf ("%f", &r);
		getchar();/*serve ad elimunare il simbolo di invio dal buffer 
					di lettura, residuo della lettura del raggio al passo 
					precedente. */
		calcola (&r, &c, &a);
		stampa (&r, &c, &a);
		printf("Vuoi continuare ? S/N: ");
		scanf ("%c", &continuare);
	} while (continuare =='S' || continuare =='s');
 return 0;
}// fine main

//definizione funzioni

void calcola (float *r,float *c, float *a){
	
	*c = 2* PIG *(*r);
//	*a = PIG *(*r)^2;
	*a = PIG *(*r)*(*r);
}

void stampa (float *r,float *c, float *a){
	printf ("Il raggio vale: %5.2f;\n", *r);
	printf ("La circonferenza vale: %5.2f;\n", *c);
	printf ("L'area del cerchio vale: %5.2f;\n", *a);
	
}
