/* Consegnare l’elaborato nella cartella condivisa in google drive.
Svolgere il tracciato dei programmi su carta intestata con nome e cognome e consegnare le foto dei fogli in
un unico file pdf.
Alla fine del tracciato scrivere cosa stampa questo programma quando viene eseguito.

Attenzione: fare il tracciato significa scrivere passo passo tutto ciò che fa il programma durante l'esecuzio-
ne ed evidenziando l'evolversi del contenuto delle variabili ad ogni istruzione eseguita. */

#include <stdio.h>
#define N 5
int vett[N];
main() {
	int i;
    for (i=0;i<N;i++)
        vett[i]=i+4;
    i=0;    
    while (i<N){
        vett[i] = vett[vett[i] % (N-i)];
        i++;
	}
	i=0;
    do {
		if (i%2)
		printf("%d",vett[i]);
		i++;
	} while (i<N);
		
}
