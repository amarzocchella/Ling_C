#include <stdio.h>
#define N 10
int vett[N];
void scambia(int *a,int *b) {
    int c;
    c=*a; *a=*b; *b=c;
}
main() {
    int i;
    for (i=0;i<N;i++)
        vett[i]=i;
    for (i=N-1;i>=0;i--)
        scambia(&vett[i],&vett[i%3]);
    for (i=0;i<N;i++)
        printf("%d ",vett[i]);
}

/* output
 * con N 10
 * 3 4 5 6 7 8 9 1 2 0
 * con N 5
 * 3 4 2 0 1
 * */
 
