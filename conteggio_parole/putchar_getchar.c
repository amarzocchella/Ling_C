/* putchar_getchar.c
 * comandi da console
ls
cd ConteggioParole
gcc putchar_getchar.c -o putchar_getchar
./putchar_getchar

es. frase di test: Ciao, come va con la programmazione, e' dura, vero?
 */
#include <stdio.h>
#define dim 100
int main(){	
  char nome[dim];
  int i,n,N=0;
  char ch;

  printf("inserisci il nome ");
  ch=getchar();

  while(ch!='\n' && N<dim)
  { 
     nome[N++]=ch;
     ch=getchar();
  }

  for(i=0; i<N; i++)
      putchar(nome[i]);

  return 0;
}
