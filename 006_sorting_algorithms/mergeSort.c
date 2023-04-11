#include <stdio.h>

// Função para mesclar dois subvetores ordenados em um único vetor ordenado
void merge(int arr[], int left[], int left_size, int right[], int right_size)
{
    int i = 0, j = 0, k = 0;

    while (i < left_size && j < right_size)
    {
        if (left[i] <= right[j])
        {
            arr[k++] = left[i++];
        }
        else
        {
            arr[k++] = right[j++];
        }
    }

    // Copia os elementos restantes do subvetor esquerdo, se houver
    while (i < left_size)
    {
        arr[k++] = left[i++];
    }

    // Copia os elementos restantes do subvetor direito, se houver
    while (j < right_size)
    {
        arr[k++] = right[j++];
    }
}

// Função de ordenação do Merge Sort
void mergeSort(int arr[], int size)
{
    if (size <= 1)
    {
        return; // Já está ordenado
    }

    int mid = size / 2;
    int left[mid];
    int right[size - mid];

    // Copia os elementos para os subvetores esquerdo e direito
    for (int i = 0; i < mid; i++)
    {
        left[i] = arr[i];
    }
    for (int i = mid; i < size; i++)
    {
        right[i - mid] = arr[i];
    }

    // Chamadas recursivas para ordenar os subvetores esquerdo e direito
    mergeSort(left, mid);
    mergeSort(right, size - mid);

    // Combina os subvetores ordenados
    merge(arr, left, mid, right, size - mid);
}

int main()
{
    int arr[] = {4, 2, 7, 1, 3, 6, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Vetor original: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    mergeSort(arr, size);

    printf("\nVetor ordenado: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
