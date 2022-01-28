// cerchio_fz_Array_c.c

/*

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

int main (void){
	float r=0, c=0,a=0;
	char continuare;
    int dim = sizeof(ArrayDiRaggi) / sizeof(ArrayDiRaggi[0]);

	printf("Vuoi fare i calcoli con raggio Random? S/N: ");
	scanf ("%c", &continuare);
    while (continuare =='S' || continuare =='s') {

        // LeggiRaggioDaArray
		printf ("Dimensione ArrayDiRaggi: %i;\n", dim);
	    for (int i = 0; i< dim; i++) {
		printf ("ArrayDiRaggi[ %d] =%5.2f;\n", i, ArrayDiRaggi[i]);

        }
        int indice = rand() % dim;
        printf ("indice rand: %i; ArrayDiRaggi[%i] = %5.2f\n", indice,indice,ArrayDiRaggi[indice]);
        r = ArrayDiRaggi[indice];

		// calcola
		c = 2* PIG * r;
           	a = PIG * r * r;

       //  stampa

			printf ("Il raggio vale: %5.2f;\n", r);
            printf ("La circonferenza vale: %5.2f;\n", c);
            printf ("L'area del cerchio vale: %5.2f;\n", a);


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
		// calcola
			c = 2* PIG * r;
            a = PIG * r * r;

       //  stampa

			printf ("Il raggio vale: %5.2f;\n", r);
            printf ("La circonferenza vale: %5.2f;\n", c);
            printf ("L'area del cerchio vale: %5.2f;\n", a);
		// chiediamo se vuole l'utente continuare
		printf("Vuoi continuare ? S/N: ");
		scanf ("%c", &continuare);
	} while (continuare =='S' || continuare =='s');
 return 0;
}// fine main


/*
L'output generato durante il test del programma:
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
