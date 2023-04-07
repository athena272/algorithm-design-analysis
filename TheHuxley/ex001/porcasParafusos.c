#include <stdio.h>
#include <stdlib.h>

int *gerar(int a, int b)
{
    int size = b - a + 1;
    int *list = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        list[i] = a + i;
    }

    return list;
}

int *merge_two(int *arr1, int size1, int *arr2, int size2)
{
    int i = 0, j = 0, k = 0;
    int *arr3 = (int *)malloc((size1 + size2) * sizeof(int));

    while (i < size1 && j < size2)
    {
        if (arr1[i] < arr2[j])
        {
            arr3[k] = arr1[i];
            i++;
        }
        else
        {
            arr3[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < size1)
    {
        arr3[k] = arr1[i];
        i++;
        k++;
    }

    while (j < size2)
    {
        arr3[k] = arr2[j];
        j++;
        k++;
    }

    return arr3;
}

int main()
{
    int num_caixas;
    while (scanf("%d", &num_caixas) != EOF)
    {
        int elem1, elem2, valor;

        int **pares = (int **)malloc(num_caixas * sizeof(int *));
        int *tamanhos = (int *)malloc(num_caixas * sizeof(int));

        for (int i = 0; i < num_caixas; i++)
        {
            scanf("%d %d", &elem1, &elem2);
            pares[i] = gerar(elem1, elem2);
            tamanhos[i] = elem2 - elem1 + 1;
        }

        int size = tamanhos[0];
        int *merged = pares[0];

        for (int i = 1; i < num_caixas; i++)
        {
            int *new_merged = merge_two(merged, size, pares[i], tamanhos[i]);
            free(merged);
            merged = new_merged;
            size += tamanhos[i];
        }

        scanf("%d", &valor);

        int comeco = -1;
        int fim = -1;

        for (int i = 0; i < size; i++)
        {
            if (merged[i] == valor)
            {
                if (comeco == -1)
                {
                    comeco = i;
                }
                fim = i;
            }
        }

        if (comeco != -1)
        {
            printf("%d encontrado de %d a %d\n", valor, comeco, fim);
        }
        else
        {
            printf("%d nao encontrado\n", valor);
        }

        free(pares);
        free(merged);
        free(tamanhos);
    }

    return 0;
}