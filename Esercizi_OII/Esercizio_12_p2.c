#define N 10
int vett[N];
void p () {
    int i;
    for (i=0;i<N;i++)
        vett[i]=i;
    for (i=0;i<N;i++)
        vett[i] = vett[vett[i] % (N-i)];
}
