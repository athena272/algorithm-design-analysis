#include <stdio.h>
#include <math.h>

// Define uma macro para realizar a troca de valores entre duas variáveis
#define SWAP(x, y)    \
    {                 \
        int temp = x; \
        x = y;        \
        y = temp;     \
    }

// Define uma estrutura de dados para representar as coordenadas x e y
struct data
{
    int x, y;
};

// Define um novo nome para a estrutura de dados
typedef struct data MAKE;

// Declaração de um array de MAKE (estruturas de dados)
MAKE m[100];

// Função de ordenação rápida (Quick Sort)
void my_sort(int left, int right)
{
    if (right > left)
    {
        int split, next;
        split = left;
        // Particionamento do array com base no valor de x
        for (next = split + 1; next <= right; next++)
            if (m[left].x < m[next].x)
            {
                split++;
                SWAP(m[next].x, m[split].x);
                SWAP(m[next].y, m[split].y);
            }
        SWAP(m[left].x, m[split].x);
        SWAP(m[left].y, m[split].y);
        // Recursivamente ordena as duas partições à esquerda e à direita do pivô
        my_sort(left, split - 1);
        my_sort(split + 1, right);
    }
}

// Função para calcular o resultado
double result(int n)
{
    double sum;
    int pre_x, pre_y, temp_x, temp_y;

    sum = 0;
    temp_y = pre_y = m[0].y;
    temp_x = pre_x = m[0].x;
    for (int i = 1; i < n; i++)
    {
        if (m[i].y > temp_y)
        {
            int x = pre_x - m[i].x;
            int y = m[i].y - pre_y;
            // Cálculo do resultado com base nas coordenadas x e y
            sum += (double)(m[i].y - temp_y) * sqrt((double)x * x + y * y) / (m[i].y - pre_y);
            temp_x = m[i].x;
            temp_y = m[i].y;
        }
        pre_x = m[i].x;
        pre_y = m[i].y;
    }
    return sum;
}

// Função principal (main)
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d%d", &m[i].x, &m[i].y);
        my_sort(0, n - 1);
        printf("%.2lf\n", result(n));
    }
    return 0;
}
