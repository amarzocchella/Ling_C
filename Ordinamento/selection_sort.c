#include <stdio.h>
#define DimMax 10
int lunghezza;
//int arr[DimMax];
int arr[] = {32, 53, 28, 85, 21, 4, 33, 26, 2, 10};

int main()
{
    int i,j;
    int numero_minore;

// inizio lettura
/*legge la dimensione del vettore e il vettore*/

 /* per i test non voglio leggere. Quindi inizializzo lunghezza 
  * e metto sotto commento il ciclo di lettura da tastiera
  */
 lunghezza = DimMax;
/*
	printf("scrivi la dimensione del vettore massimo %d: ",DimMax);
	scanf("%d%",&lunghezza);
	i=0;
	while (i<lunghezza)
	{	printf("arr[%d] = ",i);
		scanf("%d",&arr[i]);
		i++;
	}
*/
// inizio selection_sort

 

    for (i = 0; i < lunghezza-1; i++){

        numero_minore = i;

        for (j = i + 1; j < lunghezza; j++){

            if (arr[j] < arr[numero_minore]) {
                numero_minore = j;
            }

		}

        int tmp = arr[i];
        arr[i] = arr[numero_minore];
        arr[numero_minore] = tmp;
    }
 //fine selection_sort
 
 // Stampo l'array ordinato
 i=0;
 	while (i<lunghezza)
	{	printf("\narr[%d] = %4d; \n ",i, arr[i]);
		i++;
	}
	printf("\n ");
 
} //fine 
