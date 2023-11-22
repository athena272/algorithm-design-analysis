#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[25];
    float preco;
} Material;

int comparaMateriais(const void *a, const void *b)
{
    Material *matA = (Material *)a;
    Material *matB = (Material *)b;
    return strcmp(matA->nome, matB->nome);
}

int main()
{
    float dinheiro;
    int n;
    scanf("%f", &dinheiro);
    scanf("%d", &n);
    Material *materiais = (Material *)malloc(n * sizeof(Material));
    for (int i = 0; i < n; i++)
    {
        scanf("%s %f", materiais[i].nome, &materiais[i].preco);
    }

    // Ordena a lista de materiais em ordem alfabética
    qsort(materiais, n, sizeof(Material), comparaMateriais);

    // Cria um vetor de inteiros para marcar quais materiais foram comprados
    int *comprados = (int *)calloc(n, sizeof(int));

    // Seleciona os materiais que cabem no orçamento de Ambrósio
    float dinheiroRestante = dinheiro;
    int numComprados = 0;
    for (int i = 0; i < n; i++)
    {
        if (materiais[i].preco <= dinheiroRestante)
        {
            dinheiroRestante -= materiais[i].preco;
            comprados[i] = 1;
            numComprados++;
        }
    }

    // Imprime os materiais comprados em ordem alfabética
    for (int i = 0; i < n; i++)
    {
        if (comprados[i])
        {
            printf("%s %.2f\n", materiais[i].nome, materiais[i].preco);
        }
    }

    // Imprime o dinheiro restante
    printf("%.2f\n", dinheiroRestante);

    free(materiais);
    free(comprados);

    return 0;
}
