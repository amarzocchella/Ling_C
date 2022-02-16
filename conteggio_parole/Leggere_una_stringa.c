/*
comandi da console
ls
cd ConteggioParole
gcc Leggere_una_stringa.c -o Leggere_una_stringa
./Leggere_una_stringa

Premessa: vedi dispensina Lezione9_C_array_di_caratteri

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
  char s[30];
  printf("inserisci la stringa: ");
  scanf("%s",s); // Notare che non serve &
 // sizeof(s); 
  printf("%d \n",sizeof(s));
  int LunghezzaStringa = 0;
  int i = 0;
  while (i<30 && (int)s[i]!=10) LunghezzaStringa++;
   printf("LunghezzaStringa = %d \n",LunghezzaStringa);
// Attenzione il seguente ciclo cerchera' di stasmpate anche elementi inesistenti dell'array di caratteri s.
//  for(int i=0;i<30;i++)
  for(int i=0;i<LunghezzaStringa;i++)
    printf("%c",s[i]);
  printf("\n");
  printf("%s",s);
  return 0;

 }// fine main
