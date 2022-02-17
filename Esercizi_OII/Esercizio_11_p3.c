// cosa stampa questo programma? punti 3
#include <stdio.h>
int f (int i) {
    if (i<=1)
        return(i);
    else if (i%2==0)
        return(-i*f(i-1));
    else
        return(i*f(i-1)); }
main() {
    printf("num = %d",f(5));
}

/* output
 * f(5) --> 120
 * */
