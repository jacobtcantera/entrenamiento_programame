/* LIBRERÍAS */
#include <stdio.h>
#include <stdlib.h>

/* CONSTANTES */
const int N = 6;
const int P = 1;
const int DIAS_MES[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/* DECLARACIÓN FUNCIONES */
int continuar(int* valores);
void imprimeVector(int* numeros);

/* PROGRAMA */
int main(int argc, char** argv)
{
    int i, noCumpleanyos;
    int* numeros;

    /* Asignamos memoria */
    if ((numeros = malloc(N * sizeof(int))) == NULL)
    {
        printf("Sin memoria suficiente");
        return;
    }

    while (1)
    {
        /* Leemos de la entrada estandar directamente */
        for (i = 0; i < N; i++)
            scanf("%d", &numeros[i]);
        if (!continuar(numeros))
            break;
        noCumpleanyos = calcularNoCumpleanyos(numeros);
        printf("%d\n", noCumpleanyos);
    }

    /* Liberamos memoria */
    free(numeros);
    numeros = NULL;
}

int calcularNoCumpleanyos(int* n)
{
    int i, suma, deltaD, deltaM, deltaA;

    if (*n == *(n + 3) && *(n + 1) == *(n + 4))
        suma = 0;
    else
    {
        deltaD = *(n + 3) - *(n + 0);
        deltaM = *(n + 4) - *(n + 1);
        deltaA = *(n + 5) - *(n + 2);

        /* Sumamos días del primer mes y del último */
        suma = DIAS_MES[*(n + 1)] - *n + *(n + 3);

        /* Todos los días de cada año */
        suma += + deltaA * 364;

        /* Calculamos días sumados de más del primer año  y los quitamos */
        for (i = 1; i < *(n + 1) + 1; i++)
            suma -= DIAS_MES[i];

        /* Calculamos días nos sumados del último año y los sumamos */
        for (i = 1; i < *(n + 4); i++)
            suma += DIAS_MES[i];

        /* Sumamos uno en caso de que este año aún no haya habido cumpleaños */
        if (deltaM < 0)
            suma += 1;
        else if (deltaD < 0)
            suma += 1;
    }
    return suma;
}

void imprimeVector(int* numeros)
{
    int i;
    for (i = 0; i < N; i++)
        printf("%d ", *numeros++);
    printf("\n");
}

/**
    @brief Comprobacion de final de test

    Comprobación de haber llegado al único caso de prueba. A este se llega
    si tenemos una línea con seis ceros.

    @param valores vector con valores de un caso concreto

    @returns  1 -> continuamos con tests
              0 -> acabamos tests
*/
int continuar(int* valores)
{
    int i;
    for (i = 0; i < N; i++)
        if (*(valores + i) != 0)
            return 1;
    return 0;
}



