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
inline void swap(int* k, int n, int m);
long long int selectionSort(int* k, int n);
long long int insertionSort(int* k, int n);


long long int insertionSort(int* k, int n)
{
    int i, j;
    long long int suma = 0;
    for (i = 0; i < n; i++)
    {
        for (j = i; j > 0; j--)
            if (*(k + j) < *(k + j - 1))
            {
                swap(k, j, j - 1);
                suma++;
            }
            else
                break;
    }
    return suma;
}

int main(int argc, char** argv)
{
    int i, n;
    int* valores;
    long long int desajuste;

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
        // desajuste = bubbleSort(valores, &n);
        // desajuste = mergeSort(valores, n);
        // desajuste = selectionSort(valores, n);
        desajuste = insertionSort(valores, n);
        imprimeVector(valores, &n);

        printf("%lld\n", desajuste);
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
        // aux = *(k + i);
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
 * @brief Comprobación de condición de salida para BubbleSort
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

/**
 * @brief Metodo auxiliar para intercambiar posicion para
 *        SelectionSort
 *
 * Metodo auxiliar para intercambiar valores de dos posiciones de
 * un vector. Inline para forzar (aunque el compilador deberia
 * hacerlo por si mismo), puesto que en vectores de cierta
 * importancia ya se notara.
 *
 * @param k Vector de enteros
 * @param n Primera posicion a cambiar
 * @param m Segunda posicion a cambiar
 */
inline void swap(int* k, int n, int m)
{
    int a = *(k + n);
    k[n] = *(k + m);
    k[m] = a;
}

/**
 * @brief Calculo de inversiones mediante SelectionSort
 *
 * Calculo de inversiones mediante SelectionSort, metodo mucho mas
 * rapido que el BubbleSort, pese a ser tambien O(N^2). En este
 * caso si tienen mucha importancia el resto de factores.
 *
 * Comparandolo con mi primera rutina de calculo del desajuste
 * se ve que es igual que aquella, es decir no sirve. No es igual
 * porque aqui ordenamos y alli no, pero la base es exactamente
 * igual.
 *
 * @param  k Vector a ordenar
 * @param  n Longitud del vector
 * @return   Numero de inversiones
 */
long long int selectionSort(int* k, int n)
{
    int i, j, min;
    long long int suma = 0; // Me lo inicializa a 0 por defecto,
    // pero mejor hacerlo por si el compilador no lo hiciese

    for (i = 0; i < n; i++)
    {
        min = i;
        for (j = i+1; j < n; j++)
        {
            if (*(k + i) > *(k + j))
            // if (*(k + j) < *(k + min))
            {
                // min = j;
                // Poner aqui esto y cambiar la firma al if
                // me cambia el metodo. Ya no es SelectionSort,
                // aqui hacemos menos comparaciones, pero en
                // cambio hacemos muchos mas swaps. Con este
                // cambio me queda algo muy similar a insertionSort
                swap(k, i, j);
                suma++;
            }
        }
        // swap(k, i, min);
    }
    return suma;
}

/**
 * [mergeSort description]
 * @param  k [description]
 * @param  n [description]
 * @return   [description]
 */
long long int mergeSort(int* k, int n)
{
    if (n < 2)
        return 0;
    int m = n / 2;
    int r = n - m;

    return mergeSort(k, m) + mergeSort(k + m, r) + merge(k, n, m);
}

/**
 * [merge description]
 * @param  a [description]
 * @param  n [description]
 * @param  m [description]
 * @return   [description]
 */
long long int merge(int* a, int n, int m)
{
    int i, j, k, temp;
    long long int desajuste = 0;
    int *aux = malloc(n * sizeof (int));
    for (i = 0, j = m, k = 0; k < n; k++)
    {
        if (j == n)
        {
            aux[k] = a[i++];
        }
        else if (i == m)
            aux[k] = a[j++];
        else if (a[j] < a[i])
        {
            desajuste +=  n - j;
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

void imprimeVector(int* numeros, int* k)
{
    int i;
    for (i = 0; i < *k; i++)
        printf("%d ", *numeros++);
    printf("\n");
}

