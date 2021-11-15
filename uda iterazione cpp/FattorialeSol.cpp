/* File: fattorialeSol.c                                                      */
/* Time-stamp: "2017-09-06 03:26:06 paolo"                                    */
/* Scopo: uso del ciclo for - passo negativo - controllo input                */
// Sviluppato con: Dev-C++ 5.4.1  
#include <stdio.h>
#define TAPPO 0
main()
{
  long numero, conta, fatt = 0; 
  do{                            // ciclo esterno terminante con immissione di 0
    fatt = 1;                    // inizializza il fattoriale           
    do{ 
      printf("\ninserisci il numero : ");      
      scanf("%d",&numero);
      if (numero < 0)
        printf("\nattenzione: il numero deve essere positivo!"); 
      if (numero > 14)
        printf("\nattenzione: il numero deve inferiore a 14!"); 
    }while((numero < 0)||(numero > 14));
    if (numero > 0)
      for (conta = numero; conta > 1; conta--){              
        fatt = fatt*conta;                             // calcolo del fattoriale
      }
    printf("il fattoriale di %4d e' %12d",numero,fatt);// stampa il fattoriale
  }while(numero != TAPPO);

  printf("\n\n");

}
