#include <stdlib.h>
#include <stdio.h>

const int N = 100000;

int rdtsc()
{
    __asm__ __volatile__("rdtsc");
}

int main()
{
    int i;
    srand(rdtsc());

    FILE* fout;
    fout = fopen("230_casos_prueba_extremos.txt", "w");

    fprintf(fout, "%d\n", N);

    for (i = 0; i < N; i++)
        fprintf(fout, "%d ", rand() % N);

    fprintf(fout, "\n%d\n", 0);
    return 0;
}
