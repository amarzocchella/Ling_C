// cosa stampa questo programma? punti 2
#include <stdio.h>
#define N 5
int vett[N];
void p () {
    int i;
    for (i=0;i<N;i++)
        vett[i]=i+3;
    for (i=0;i<N;i++)
        vett[i] = vett[vett[i] % (N-i)];
}
main() {
	p ();
    for (int i=0;i<N;i++)
		printf("%d",vett[i]);
}
/* output
 * N = 5 e i+1 --> 23222
 * ... i+1 --> 23222
 * ... i+2 --> 45554
 * ... i+3 --> 66566
 * */
