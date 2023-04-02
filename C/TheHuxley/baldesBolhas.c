#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int n;
    while (true)
    { // loop para processar vários casos de teste
        scanf("%d", &n);
        if (n == 0)
            break; // condição de saída

        int p[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &p[i]); // leitura da permutação inicial
        }

        int inv = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (p[i] > p[j])
                    inv++; // contagem de inversões na permutação
            }
        }

        if (inv % 2 == 0)
            printf("Carlos\n"); // decisão de quem é o vencedor
        else
            printf("Marcelo\n");
    }
    return 0;
}
