#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

double merge(int lista[], int inicio, int meio, int fim)
{
    int left[meio - inicio + 1];
    int right[fim - meio];
    double inversoes = 0;

    for (int i = 0; i < meio - inicio + 1; i++)
    {
        left[i] = lista[inicio + i];
    }

    for (int i = 0; i < fim - meio; i++)
    {
        right[i] = lista[meio + 1 + i];
    }

    int top_left = 0;
    int top_right = 0;

    for (int k = inicio; k <= fim; k++)
    {
        if (top_left >= meio - inicio + 1)
        {
            lista[k] = right[top_right];
            top_right++;
        }
        else if (top_right >= fim - meio)
        {
            lista[k] = left[top_left];
            top_left++;
        }
        else if (left[top_left] < right[top_right])
        {
            lista[k] = left[top_left];
            top_left++;
        }
        else
        {
            lista[k] = right[top_right];
            top_right++;
            inversoes += meio - inicio + 1 - top_left;
        }
    }
    return inversoes;
}

double mergeSort(int lista[], int inicio, int fim)
{
    double inversoes = 0;
    if (fim > inicio)
    { // Corrigido: foi alterado fim - inicio > 0 para fim > inicio
        int meio = (inicio + fim) / 2;
        inversoes += mergeSort(lista, inicio, meio);
        inversoes += mergeSort(lista, meio + 1, fim);
        inversoes += merge(lista, inicio, meio, fim);
    }

    return inversoes;
}

int main()
{
    int n;
    double inversoes;
    while (1)
    {
        scanf("%d", &n);
        if (n == 0)
            break;
        int array[n];
        for (int i = 0; i < n; i++)
            scanf("%d", &array[i]);

        inversoes = mergeSort(array, 0, n - 1);

        printf("%s\n", ((int)inversoes) % 2 == 0 ? "Carlos" : "Marcelo");
    }

    return 0;
}
