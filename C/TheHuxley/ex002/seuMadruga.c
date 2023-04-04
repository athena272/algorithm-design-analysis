#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define PRECISAO 0.00001

int main()
{

    int N, A;
    while (scanf("%d %d", &N, &A) && (N || A))
    {
        int *comprimentos = (int *)malloc(N * sizeof(int));
        int i;
        for (i = 0; i < N; i++)
        {
            scanf("%d", &comprimentos[i]);
        }

        int soma = 0;
        for (i = 0; i < N; i++)
        {
            soma += comprimentos[i];
        }

        if (soma < A)
        {
            printf("-.-\n");
            free(comprimentos);
            continue;
        }

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

            if (area > A)
            {
                esquerda = altura;
            }
            else
            {
                direita = altura;
            }
        }

        if (esquerda == 0.0 || direita == soma)
        {
            printf(":D\n");
        }
        else
        {
            printf("%.4f\n", esquerda);
        }

        free(comprimentos);
    }

    return 0;
}