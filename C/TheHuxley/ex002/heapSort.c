#include <stdio.h>

#define MAX 1000

void heapify(int arr[], int n, int i)
{
    int largest = i; // inicializa o maior como raiz
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // se o filho esquerdo for maior que a raiz
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // se o filho direito for maior que o maior até agora
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // se o maior não é a raiz
    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // heapify na subárvore afetada
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    // constrói heap (reorganiza array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    printf("Estado inicial: ");
    for (int i = 0; i < n; ++i)
        printf("%d | ", arr[i]);
    printf("\n");

    // extrai os elementos um por um
    for (int i = n - 1; i >= 0; i--)
    {
        // move o atual elemento raiz para o final
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // chama max heapify na heap reduzida
        heapify(arr, i, 0);

        printf("Estado Atual da Heap: ");
        for (int j = 0; j < i; ++j)
            printf("%d | ", arr[j]);
        printf("\n");

        printf("Maior elemento neste passo: %d\n", arr[0]);
    }

    printf("Resultado Final: ");
    for (int i = 0; i < n; ++i)
        printf("%d | ", arr[i]);
    printf("\n");
}

int readArray(int arr[])
{
    int n = 0;
    while (scanf("%d", &arr[n]) == 1) // enquanto ler um número inteiro
    {
        n++; // incrementa o tamanho do array
    }
    return n; // retorna o tamanho do array
}

int main()
{
    int arr[MAX];
    int n = readArray(arr); // lê a lista de números e armazena no array

    heapSort(arr, n); // chama a função heapSort para ordenar o array

    return 0;
}
