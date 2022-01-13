/*
Quando un array viene passato come parametro alla funzione, 
viene considerato come un puntatore. 
L’operatore sizeof() restituisce la dimensione del puntatore 
invece della dimensione dell’array. 
Quindi all’interno delle funzioni, questo metodo non funzionerà. 
Invece, passa un parametro aggiuntivo size_t size per indicare 
il numero di elementi nell’array.
*/
#include<stdio.h>
#include<stdlib.h>

void printSizeOfIntArray(int intArray[]);
void printLengthIntArray(int intArray[]);

int main(int argc, char* argv[])
{
    int integerArray[] = { 0, 1, 2, 3, 4, 5, 6 };

    printf("sizeof of the array is: %d\n", (int) sizeof(integerArray));
    printSizeOfIntArray(integerArray);
    
    printf("Length of the array is: %d\n", (int)( sizeof(integerArray) / sizeof(integerArray[0]) ));
    printLengthIntArray(integerArray);

}

void printSizeOfIntArray(int intArray[])
{
    printf("sizeof of the parameter is: %d\n", (int) sizeof(intArray));
}

void printLengthIntArray(int intArray[])
{
    printf("Length of the parameter is: %d\n", (int)( sizeof(intArray) / sizeof(intArray[0]) ));
}

/*
L'output è
sizeof of the array is: 28
sizeof of the parameter is: 4
Length of the array is: 7
Length of the parameter is: 1
*/
