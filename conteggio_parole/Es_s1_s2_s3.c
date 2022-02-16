/*
comandi da console
ls
cd ConteggioParole
gcc Es_s1_s2_s3.c -o Es_s1_s2_s3
./Es_s1_s2_s3

Es_s1_s2_s3: vedi dispensina Lezione9_C_array_di_caratteri

In memoria le stringhe sono degli array di tipo char null
terminated …
… array di caratteri con la particolarità che l’elemento
che segue l'ultimo carattere deve contenere il carattere NULL
('\0' terminatore)
Consente a operatori e funzioni di distinguere stringhe da normali
array
char s1[] = {'h','e','l','l','o'}
char s2[] = {'h','e','l','l','o','\0'}
char s3[] = "hello"; ( s1 non è una stringa, ma un array di caratteri
s2 e s3 sono stringhe e sono uguali)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
 // int i, cont  =  0 ;
 char s1[] = {'h','e','l','l','o'};
 char s2[] = {'h','e','l','l','o','\0'};
 char s3[] = "hello"; /* s1 non è una stringa, ma un array di caratteri
						s2 e s3 sono stringhe e sono uguali)
						Attenzione: sono comunque array di caratteri e la print con %s funziona
						correttamente*/
  printf ("s1 = %s\n", s1);
  printf ("s2 = %s\n", s2);
  printf ("s3 = %s\n", s3);


  printf("%d \n",sizeof(s1));
  int LunghezzaStringa = sizeof(s1);
  int i = 0;
  while (i<LunghezzaStringa ){
   printf("s1[ %d ] = %c ",i, s1[i]);
   i++;
   }
  printf("\n");

  for(int i=0;i<LunghezzaStringa;i++)
   printf("%c",s1[i]);
  printf("\n");
 }// fine main


/* output
s1 = hello
s2 = hello
s3 = hello
*/
