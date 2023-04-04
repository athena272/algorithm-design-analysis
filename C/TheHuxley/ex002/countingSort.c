#include <stdio.h>
#include <stdlib.h>

// Função para ordenação por contagem
void counting_sort(int *A, int *C, int n, int k)
{
    int i, j;

    // Inicializando o array de contagem C com 0
    for (i = 0; i <= k; i++)
    {
        C[i] = 0;
    }

    // Contando o número de ocorrências de cada elemento em A
    for (j = 0; j < n; j++)
    {
        C[A[j]] = C[A[j]] + 1;
    }

    // Calculando a posição de cada elemento no array ordenado
    for (i = 1; i <= k; i++)
    {
        C[i] = C[i] + C[i - 1];
    }

    // Construindo o array ordenado
    int *B = malloc(n * sizeof(int));
    for (j = n - 1; j >= 0; j--)
    {
        B[C[A[j]] - 1] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }

    // Imprimindo o array de contagem
    for (i = 0; i <= k; i++)
    {
        printf("%d ", C[i]);
    }
    printf("\n");

    // Imprimindo o array ordenado
    for (i = 0; i < n; i++)
    {
        printf("%d ", B[i]);
    }
    printf("\n");

    free(B);
}

int main()
{
    int n, i, k = 0;

    scanf("%d", &n);

    // Lendo o array A e encontrando o maior valor k
    int *A = malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
        if (A[i] > k)
        {
            k = A[i];
        }
    }

    // Criando o array de contagem C
    int *C = malloc((k + 1) * sizeof(int));

    counting_sort(A, C, n, k);

    free(A);
    free(C);

    return 0;
}
