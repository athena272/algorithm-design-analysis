#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int merge(int arr[], int temp[], int left, int mid, int right)
{
    int i = left;       // Índice para a primeira metade do vetor
    int j = mid + 1;    // Índice para a segunda metade do vetor
    int k = left;       // Índice para o vetor temporário
    int inversions = 0; // Contador de inversões

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            inversions += (mid - i + 1); // Contar inversões
        }
    }

    // Copiar os elementos restantes da primeira metade, se houver
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }

    // Copiar os elementos restantes da segunda metade, se houver
    while (j <= right)
    {
        temp[k++] = arr[j++];
    }

    // Copiar o vetor temporário de volta para o vetor original
    for (int x = left; x <= right; x++)
    {
        arr[x] = temp[x];
    }

    return inversions;
}

int mergeSort(int arr[], int temp[], int left, int right)
{
    int inversions = 0; // Contador de inversões

    if (left < right)
    {
        int mid = (left + right) / 2; // Encontrar o meio do vetor

        // Recursivamente ordenar as duas metades do vetor
        inversions += mergeSort(arr, temp, left, mid);
        inversions += mergeSort(arr, temp, mid + 1, right);

        // Combinar as duas metades ordenadas e contar as inversões
        inversions += merge(arr, temp, left, mid, right);
    }

    return inversions;
}

int main()
{
    int N, X[100000], temp[100000]; // Vetor X e vetor temporário com tamanho máximo de 100000

    while (1)
    {                    // Loop infinito para ler múltiplos casos de teste
        scanf("%d", &N); // Ler o valor de N
        if (N == 0)
            break; // Se N for zero, sair do loop

        for (int i = 0; i < N; i++)
        {
            scanf("%d", &X[i]); // Ler a sequência de inteiros X
        }

        int inversions = mergeSort(X, temp, 0, N - 1); // Ordenar X e contar inversões

        if (inversions % 2 == 0)
        {
            printf("Carlos\n"); // Se o número de inversões for par, Carlos ganha
        }
        else
        {
            printf("Marcelo\n"); // Caso contrário, Marcelo ganha
        }
    }

    return 0;
}