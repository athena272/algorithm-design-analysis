#include <stdio.h>

double merge(int lista[], int inicio, int meio, int fim)
{
    int inversoes = 0;
    int tam_esq = meio - inicio;
    int tam_dir = fim - meio;
    int esq[tam_esq];
    int dir[tam_dir];
    int i, j, k;

    for (i = 0; i < tam_esq; i++)
    {
        esq[i] = lista[inicio + i];
    }
    for (j = 0; j < tam_dir; j++)
    {
        dir[j] = lista[meio + j];
    }

    i = 0;
    j = 0;
    for (k = inicio; k < fim; k++)
    {
        if (i >= tam_esq)
        {
            lista[k] = dir[j];
            j++;
        }
        else if (j >= tam_dir)
        {
            lista[k] = esq[i];
            i++;
        }
        else if (esq[i] < dir[j])
        {
            lista[k] = esq[i];
            i++;
        }
        else
        {
            lista[k] = dir[j];
            j++;
            inversoes += tam_esq - i;
        }
    }
    return inversoes;
}

double mergesort(int lista[], int inicio, int fim)
{
    int inversoes = 0;
    if (fim - inicio > 1)
    {
        int meio = (inicio + fim) / 2;
        inversoes += mergesort(lista, inicio, meio);
        inversoes += mergesort(lista, meio, fim);
        inversoes += merge(lista, inicio, meio, fim);
    }
    return inversoes;
}

int main()
{
    int jogada;
    while (1 == 1)
    {
        scanf("%d", &jogada);
        if (jogada == 1 && jogada != 0)
        {
            int p[jogada];
            for (int i = 0; i < jogada; i++)
            {
                scanf("%d", &p[i]);
            }
            int inversao = mergesort(p, 0, jogada);
            if (inversao % 2 == 0)
            {
                printf("Carlos\n");
            }
            else
            {
                printf("Marcelo\n");
            }
        }
    }

    return 0;
}
