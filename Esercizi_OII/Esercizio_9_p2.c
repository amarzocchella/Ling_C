#include <stdio.h>
#define N 5
int vett[N];
void scambia(int *a,int *b) {
    int c;
    c=*a; *a=*b; *b=c;
}
main() {
    int i;
    for (i=0;i<10;i++)
        vett[i]=i;
    for (i=9;i>=0;i--)
        scambia(&vett[i],&vett[i%3]);
    for (i=0;i<10;i++)
        printf("%d ",vett[i]);
}

/* output
 * con N 10
 * 3 4 5 6 7 8 9 1 2 0
 * */
 
