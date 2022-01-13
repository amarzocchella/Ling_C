// cerchio_fz_Array.c

/*
Quando un array viene passato come parametro alla funzione, 
viene considerato come un puntatore. 
L’operatore sizeof() restituisce la dimensione del puntatore 
invece della dimensione dell’array. Vedi esempio test_dim_array.c.
Quindi all’interno delle funzioni, questo metodo non funzionerà. 
Invece, passa un parametro aggiuntivo size_t size per indicare 
il numero di elementi nell’array.
* 
* 
* The rand() function in <stdlib.h> returns a pseudo-random integer 
* between 0 and RAND_MAX. You can use srand(unsigned int seed) to set a seed.

It's common practice to use the % operator in conjunction with rand() 
to get a different range (though bear in mind that this throws off 
the uniformity somewhat). For example:

// random int between 0 and 19 
int r = rand() % 20;
*/
// #include <iostream> // in C++
#include <stdio.h>
#include <stdlib.h>

#define PIG 3.14
// oppure
const float PGreco = 3.14;

// Dichiarazioni var globali
float ArrayDiRaggi[]={3.0,3.5,4.0,4.5};
/*using namespace std; serve in C++ per accedere a cin e cout senza dovere 
						utilizzare std::cin >>...; o std::cout <<...;*/
const float pigreco = 3.14;
//prototipi funzioni
void calcola (float *,float *, float *);
void stampa (float *,float *, float *);
void LeggiRaggioDaArray(int ,float [], float *);
int main (void){
	float r=0, c=0,a=0;
	char continuare;
    int dim = sizeof(ArrayDiRaggi) / sizeof(ArrayDiRaggi[0]);

	printf("Vuoi fare i calcoli con raggio Random? S/N: ");
	scanf ("%c", &continuare);
    while (continuare =='S' || continuare =='s') {
		LeggiRaggioDaArray(dim, ArrayDiRaggi, &r);
		calcola (&r, &c, &a);
		stampa (&r, &c, &a);

		getchar();/*serve ad elimunare il simbolo di invio dal buffer 
					di lettura, residuo della lettura al passo 
					precedente. */
		printf("Vuoi continuare con raggio Random? S/N: ");
		scanf ("%c", &continuare);
	} //fine while

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

void LeggiRaggioDaArray(int dim,float ArrayRaggi[], float *r){ 
	int indice = 0;
	printf ("Dimensione ArrayRaggi: %i;\n", dim);
	for (int i = 0; i< dim; i++) {
		printf ("ArrayRaggi[ %d] =%5.2f;\n", i, ArrayRaggi[i]);
		
	}
	indice = rand() % dim;
	printf ("indice rand: %i; ArrayRaggi[%i] = %i\n", indice,indice,ArrayRaggi[indice]);
	*r = ArrayRaggi[indice];
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
