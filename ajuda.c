#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// função que gera um array contendo todos os valores inteiros entre a e b, inclusive
int *generate(int a, int b)
{
    // calcula o tamanho do array
    int size = b - a + 1;
    // aloca memória para o array
    int *list = (int *)malloc(size * sizeof(int));
    // preenche o array com os valores de a a b
    for (int i = 0; i < size; i++)
    {
        list[i] = a + i;
    }
    // retorna o array gerado
    return list;
}

// função que une dois arrays ordenados em um único array ordenado
int *parafusosPorcas(int *arr1, int size1, int *arr2, int size2)
{
    // inicializa contadores para cada array e para o novo array que será criado
    int i = 0, j = 0, k = 0;
    // aloca memória para o novo array, que terá tamanho igual à soma dos tamanhos dos arrays de entrada
    int *arr3 = (int *)malloc((size1 + size2) * sizeof(int));
    // itera pelos dois arrays ao mesmo tempo, inserindo o menor valor no novo array até que um dos arrays seja completamente percorrido
    while (i < size1 && j < size2)
    {
        if (arr1[i] < arr2[j])
        {
            arr3[k] = arr1[i];
            i++;
        }
        else
        {
            arr3[k] = arr2[j];
            j++;
        }
        k++;
    }
    // insere os elementos restantes do primeiro array no novo array
    while (i < size1)
    {
        arr3[k] = arr1[i];
        i++;
        k++;
    }
    // insere os elementos restantes do segundo array no novo array
    while (j < size2)
    {
        arr3[k] = arr2[j];
        j++;
        k++;
    }
    // retorna o novo array
    return arr3;
}

int main()
{
    int quantityBoxes;

    // enquanto houver entrada, faça
    while (scanf("%d", &quantityBoxes) != EOF)
    {
        // cria um array vazio
        int *arr = NULL;
        // inicializa o tamanho do array como zero
        int size = 0;
        // lê os dados de cada caixa e gera um array com os tamanhos de parafusos e porcas
        for (int i = 0; i < quantityBoxes; i++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            int *tmp = generate(x, y);
            int tmp_size = y - x + 1;
            arr = parafusosPorcas(arr, size, tmp, tmp_size);
            size += tmp_size;
            free(tmp);
        }

        // lê o número que Mango quer procurar
        int numberToFind;
        scanf("%d", &numberToFind);

        // procura as posições em que o número procurado aparece no array
        int inicio = -1, fim = -1;
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == numberToFind)
            {
                if (inicio == -1)
                {
                    inicio = i;
                }
                fim = i;
            }
        }

        // imprime a resposta
        if (inicio == -1 && fim == -1)
        {
            printf("%d nao encontrado\n", numberToFind);
        }
        else
        {
            printf("%d encontrado de %d a %d\n", numberToFind, inicio, fim);
        }

        // libera a memória alocada para o array
        free(arr);
    }

    return 0;
}
