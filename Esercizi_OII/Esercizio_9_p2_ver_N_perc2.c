#include <stdio.h>
#define N 5
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
        scambia(&vett[i],&vett[i%2]);
    for (i=0;i<N;i++)
        printf("%d ",vett[i]);
}

/* output
 * con N 10
 * 2 3 4 5 6 7 8 9 0 1
 * con N 5
 * 2 3 4 1 0
 * */
 
