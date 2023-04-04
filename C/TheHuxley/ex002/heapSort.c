#include <stdio.h>

// Função para trocar dois elementos de lugar em um array
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para ajustar a heap, a partir do elemento index
void maxHeapify(int arr[], int n, int index)
{
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != index)
    {
        swap(&arr[index], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

// Função para construir a heap
void buildMaxHeap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
}

// Função para implementar o Heapsort
void heapSort(int arr[], int n)
{
    printf("Estado inicial:");
    for (int i = 0; i < n; i++)
        printf(" %d |", arr[i]);
    printf("\n");

    // Construindo a heap máxima
    buildMaxHeap(arr, n);

    // Ordenando a partir da heap máxima
    for (int i = n - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        maxHeapify(arr, i, 0);

        printf("Estado Atual da Heap:");
        for (int j = 0; j <= i; j++)
            printf(" %d |", arr[j]);
        printf("\n");

        printf("Maior elemento neste passo: %d\n", arr[i]);
    }
}

int main()
{
    // Lendo os números a serem ordenados
    int arr[100], n = 0;
    while (scanf("%d", &arr[n]) == 1)
    {
        n++;
    }

    // Chamando o Heapsort
    heapSort(arr, n);

    // Imprimindo o resultado final
    printf("Resultado Final:");
    for (int i = 0; i < n; i++)
        printf(" %d |", arr[i]);
    printf("\n");

    return 0;
}