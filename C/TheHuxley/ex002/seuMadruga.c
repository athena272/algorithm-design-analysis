#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Define a precisão da busca binária
#define PRECISAO 0.00001

int main()
{
    int N, A;

    // Lê o número de hastes (N) e o valor de A
    while (scanf("%d %d", &N, &A) && (N || A))
    {
        // Aloca um array para os comprimentos das hastes
        int *comprimentos = (int *)malloc(N * sizeof(int));
        int i;

        // Lê os comprimentos das hastes
        for (i = 0; i < N; i++)
        {
            scanf("%d", &comprimentos[i]);
        }

        // Calcula a soma dos comprimentos das hastes
        int soma = 0;
        for (i = 0; i < N; i++)
        {
            soma += comprimentos[i];
        }

        // Verifica se a soma dos comprimentos é menor que A
        if (soma < A)
        {
            // Se for, imprime "-.-" e continua para a próxima iteração
            printf("-.-\n");
            free(comprimentos);
            continue;
        }

        // Define o intervalo [0, soma] para a busca binária
        double esquerda = 0, direita = soma;
        while (direita - esquerda > PRECISAO)
        {
            double altura = (esquerda + direita) / 2.0;
            double area = 0;
            for (i = 0; i < N; i++)
            {
                if (comprimentos[i] > altura)
                {
                    area += (comprimentos[i] - altura);
                }
            }

            // Se a área é maior do que a capacidade desejada, a altura da caixa d'água deve ser aumentada
            if (area > A)
            {
                esquerda = altura;
            }
            // Caso contrário, a altura deve ser diminuída
            else
            {
                direita = altura;
            }
        }

        // Se a altura da caixa d'água é igual a zero ou à altura total das tábuas, a caixa d'água não pode ser construída
        if (esquerda == 0.0 || direita == soma)
        {
            printf(":D\n");
        }
        // Caso contrário, imprime a altura da caixa d'água com quatro casas decimais
        else
        {
            printf("%.4f\n", esquerda);
        }

        // Libera a memória alocada para os comprimentos das tábuas
        free(comprimentos);
    }

    return 0;
}