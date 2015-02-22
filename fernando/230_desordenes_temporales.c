/* Libreías */
#include <stdio.h>
#include <stdlib.h>

/* Firmas */
long long int calculoDesajuste(int* k, int* n);
inline int continuar(int* k);
void imprimeVector(int* numeros, int* k);
long long int bubbleSort(int k[], int* n);

long long int mergeSort(int* k, int n);
long long int merge(int* a, int n, int m);

long long int mergeSort(int* k, int n)
{
    if (n < 2)
        return 0;
    int m = n / 2;
    int r = n - m;
    mergeSort(k, m);
    mergeSort(k + m, r);
    merge(k, n, m);

    return 0;
}

long long int merge(int* a, int n, int m)
{
    int i, j, k;
    long long int desajuste = 0;
    int *aux = malloc(n * sizeof (int));
    for (i = 0, j = m, k = 0; k < n; k++)
    {
        if (j == n)
            aux[k] = a[i++];
        else if (i == m)
            aux[k] = a[j++];
        else if (a[j] < a[i])
        {
            desajuste += j - i;
            printf("%lld\n", n - m);
            aux[k] = a[j++];
        } else
            aux[k] = a[i++];
    }

    for (i = 0; i < n; i++)
        a[i] = aux[i];

    free(aux);
    aux = NULL;

    return desajuste;
}

int main(int argc, char** argv)
{
    int i, n;
    int* valores;

    while (1)
    {
        /* Leo el número de valores */
        scanf("%d", &n);
        if (!continuar(&n)) // Esto no me gusta nada, pero es para ajustar
            break;         // la salida a como la quieren
        /* Asigno memoria a partir de n */
        if ((valores = malloc(n * sizeof(int))) == NULL)
        {
            printf("Sin memoria para almacenar los números");
            return;
        }

        /* Leemos los valores */
        for (i = 0; i < n; i++)
            scanf("%d", &valores[i]);
        // printf("%lld\n", calculoDesajuste(valores, &n));
        // printf("%lld\n", bubbleSort(valores, &n));
        printf("%lld\n", mergeSort(valores, n));
        // imprimeVector(valores, &n);
    }

    /* Liberamos memoria */
    free(valores);
    valores = NULL;
}

/**
 * @brief Cálculo del desajuste temporal
 *
 * Cálculo del desajuste temporal, comparando todo número con los siguientes.
 * O(N^2), pero no se me ocurre otra forma.
 *
 * @param  k Valores de desajuste para cada persona
 * @param  n Número de personas que conforma la entrada
 * @return   Valor del desajuste temporal global (suma de todas las personas
 *           que lo sufren)
 */
long long int calculoDesajuste(int* k, int* n)
{
    int i, j, aux;
    long long int suma = 0;

    for (i = 0; i < *n; ++i)
    {
        aux = *(k + i);
        for (j = i + 1; j < *n; j++)
            if (*(k + i) > *(k + j))
                suma++;
    }

    return suma;
}

/**
 * @brief Cálculo mediante BubbleSort
 *
 * Cálculo mediante BubbleSort del número de desórdenes temporales, puesto que
 * al final lleva la cuenta de las inversiones que se producen, esperando que
 * al usar el mejorado fuese más rápido. Error, es bastante más lento.
 *
 * @param  k Valores de desajuste para cada persona
 * @param  n Número de personas que conforma la entrada
 * @return   Valor del desajuste temporal global (suma de todas las personas
 *           que lo sufren)
 */
long long int bubbleSort(int k[], int* n)
{
    int i, j, temp;
    long long int suma = 0;
    int desordenado = 1;

    while (desordenado)
    {
        desordenado = 0;
        for (j = 1; j < *n; j++)
            if (k[j] < k[j - 1])
            {
                desordenado++;
                temp = k[j];
                k[j] = k[j - 1];
                k[j - 1] = temp;
                suma++;
            }
    }
    return suma;
}



// void merge_sort (int *a, int n) {
//     if (n < 2)
//         return;
//     int m = n / 2;
//     merge_sort(a, m);
//     merge_sort(a + m, n - m);
//     merge(a, n, m);
// }

/**
 * @brief Comprobación de condición de salida
 *
 * Comprobación de si se sigue calculando o no, en función del número de
 * personas que se hayan de procesar.
 *
 * @param  n Número de personas
 * @return   Salida o no del programa
 */
int continuar(int* k)
{
    if (*k == 0)
        return 0;
    return 1;
}

void imprimeVector(int* numeros, int* k)
{
    int i;
    for (i = 0; i < *k; i++)
        printf("%d ", *numeros++);
    printf("\n");
}
