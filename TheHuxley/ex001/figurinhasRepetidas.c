#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

// Definição da estrutura de vetor com tamanho e elementos
typedef struct
{
    int n;         // tamanho
    int *elements; // ponteiro para os elementos
} t_vector;

// Função que recebe dois vetores ordenados e sem repetições e retorna um vetor com as figurinhas repetidas
t_vector repetidas(t_vector album, t_vector novas)
{

    // Alocar um vetor para armazenar as figurinhas repetidas
    t_vector repetidas;
    repetidas.n = 0;                                                       // começa com 0 repetições
    repetidas.elements = (int *)malloc((album.n + novas.n) * sizeof(int)); // aloca memória para o vetor de repetições

    // Inicializar variáveis para percorrer os vetores
    int i = 0, j = 0;

    // Percorrer os dois vetores enquanto houver elementos em ambos
    while (i < album.n && j < novas.n)
    {

        // Se o elemento do vetor album for menor, avança para o próximo elemento
        if (album.elements[i] < novas.elements[j])
        {
            i++;
        }
        // Se o elemento do vetor novas for menor, avança para o próximo elemento
        else if (novas.elements[j] < album.elements[i])
        {
            j++;
        }
        // Se os elementos forem iguais, adiciona ao vetor de repetições e avança nos dois vetores
        else
        {
            repetidas.elements[repetidas.n] = album.elements[i];
            repetidas.n++;
            i++;
            j++;
        }
    }

    // Liberar a memória alocada para o vetor de repetições que não foi utilizado
    repetidas.elements = (int *)realloc(repetidas.elements, repetidas.n * sizeof(int));

    return repetidas; // retorna o vetor de repetições
}

int main()
{
    int i, j, k;
    t_vector album, novas, reps;
    scanf("%d", &album.n);
    album.elements = (int *)malloc((album.n + 1) * sizeof(int));
    for (i = 0; i < album.n; i++)
    {
        scanf("%d", &(album.elements[i]));
    }
    album.elements[i] = INT_MAX; // insere um valor máximo ao final do vetor para ajudar na comparação

    scanf("%d", &novas.n);
    novas.elements = (int *)malloc((novas.n + 1) * sizeof(int));
    for (i = 0; i < novas.n; i++)
    {
        scanf("%d", &(novas.elements[i]));
    }
    novas.elements[i] = INT_MAX; // insere um valor máximo ao final do vetor para ajudar na comparação

    reps = repetidas(album, novas); // chama a função para obter as repetições

    // Imprime as figurinhas repetidas em ordem crescente
    for (k = 0; k < reps.n - 1; k++)
        printf("%d ", reps.elements[k]);
    printf("%d\n", reps.elements[k]);

    free(reps.elements);  // libera a memória alocada para o vetor de repetições
    free(album.elements); // libera a memória alocada para o vetor album
    free(novas.elements); // libera a memória alocada para o vetor novas

    return 0;
}
