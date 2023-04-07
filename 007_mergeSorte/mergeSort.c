#include <stdio.h>

// Função para mesclar dois subvetores em um único vetor
void merge(int vetor[], int inicio, int meio, int fim)
{
    int i, j, k;
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    // Criar vetores temporários
    int vetor_esquerda[n1];
    int vetor_direita[n2];

    // Copiar dados para os vetores temporários
    for (i = 0; i < n1; i++)
    {
        vetor_esquerda[i] = vetor[inicio + i];
    }
    for (j = 0; j < n2; j++)
    {
        vetor_direita[j] = vetor[meio + 1 + j];
    }

    // Mesclar os vetores temporários de volta para o vetor original
    i = 0;      // Índice inicial do primeiro subvetor
    j = 0;      // Índice inicial do segundo subvetor
    k = inicio; // Índice inicial do vetor mesclado

    while (i < n1 && j < n2)
    {
        if (vetor_esquerda[i] <= vetor_direita[j])
        {
            vetor[k] = vetor_esquerda[i];
            i++;
        }
        else
        {
            vetor[k] = vetor_direita[j];
            j++;
        }
        k++;
    }

    // Copiar os elementos restantes do vetor_esquerda[], se houver algum
    while (i < n1)
    {
        vetor[k] = vetor_esquerda[i];
        i++;
        k++;
    }

    // Copiar os elementos restantes do vetor_direita[], se houver algum
    while (j < n2)
    {
        vetor[k] = vetor_direita[j];
        j++;
        k++;
    }
}

// Função principal do Merge Sort
void merge_sort(int vetor[], int inicio, int fim)
{
    if (inicio < fim)
    {
        // Encontrar o ponto médio para dividir o vetor em dois subvetores
        int meio = inicio + (fim - inicio) / 2;

        // Ordenar os dois subvetores recursivamente
        merge_sort(vetor, inicio, meio);
        merge_sort(vetor, meio + 1, fim);

        // Mesclar os subvetores em um único vetor
        merge(vetor, inicio, meio, fim);
    }
}

// Função de teste para o Merge Sort
int main()
{
    int vetor[] = {12, 11, 13, 5, 6, 7};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    printf("Vetor original: ");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    merge_sort(vetor, 0, tamanho - 1);

    printf("Vetor ordenado: ");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
