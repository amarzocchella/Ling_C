/* dim_array.c */
#include <stdio.h>

double a[8]={5.321,364.32,0,21.7,41.2,1.31,74.36,0.998};
void lunghezza(double x[])
{
  printf("In lunghezza: La lunghezza del vettore a e' sizeof(a)/sizeof(a[0]) = %d\n",sizeof(a)/sizeof(a[0]));
  printf("sizeof(*x) = %d, sizeof(a[0]) = %d\n",sizeof(*x),sizeof(a[0]));
  printf("La lunghezza del vettore x e' sizeof(*x)/sizeof(x[0]) = %d\n",sizeof(*x)/sizeof(x[0]));
  printf("Attenzione: La lunghezza del vettore x e' sizeof(x)/sizeof(x[0]) = %d\n",sizeof(x)/sizeof(x[0]));
}

int main()
{

  printf("In main: sizeof(a) = %d, sizeof(a[0]) = %d\n",sizeof(a),sizeof(a[0]));
  printf("In main: La lunghezza del vettore a e' sizeof(a)/sizeof(a[0]) = %d\n",sizeof(a)/sizeof(a[0]));
  
  lunghezza(a);
  return 0;
}

/*
L'output è
In main: sizeof(a) = 64, sizeof(a[0]) = 8
In main: La lunghezza del vettore a e' sizeof(a)/sizeof(a[0]) = 8
In lunghezza: La lunghezza del vettore a e' sizeof(a)/sizeof(a[0]) = 8
sizeof(*x) = 8, sizeof(a[0]) = 8
La lunghezza del vettore x e' sizeof(*x)/sizeof(*x[0]) = 1
Attenzione: La lunghezza del vettore x e' sizeof(x)/sizeof(x[0]) = 0
*/
