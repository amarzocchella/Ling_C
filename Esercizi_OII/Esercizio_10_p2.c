// cosa stampa questo programma? punti 2
#include <stdio.h>
#define N 10
int v[N] = {3, 5, 2, 7, 8, 1, 4, 9, 6, 0};
void p () {
    int i,t,s;
    do {
        s=0;
        for (i=1;i<N-1;i++)
            if (v[i-1]>v[i]) {
                t=v[i-1];
                v[i-1]=v[i];
                v[i]=t;
                s=1;
            }
    }
    while (s==1);
}
main() {
    int i;
    p();
    for (i=0;i<N;i++)
        printf("%d ",v[i]);
}

/* output
 * v[N] = {3, 5, 2, 7, 8, 1, 4, 9, 6, 0};
 * 1 2 3 4 5 6 7 8 9 0
 * */
