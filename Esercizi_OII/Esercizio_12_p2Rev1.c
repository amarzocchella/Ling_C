// cosa ti aspetti che stampi questo programma?
#include <stdio.h>
#define N 3
int vett[N];
void p () {
    int i;
    for (i=0;i<N;i++)
        vett[i]=i;
    for (i=0;i<N;i++)
        vett[i] = vett[vett[i] % (N-i)];
}
main() {
	p ();
	int i = rand()% N;
	if (i % 2==0)
		printf(vett[i]);
	else printf(vett[i]);
}
