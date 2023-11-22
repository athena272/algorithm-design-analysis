#include <stdio.h>
#include <math.h>

#define SWAP(x, y)    \
    {                 \
        int temp = x; \
        x = y;        \
        y = temp;     \
    }

struct data
{
    int x, y;
};
typedef struct data MAKE;
MAKE m[100];

void my_sort(int left, int right)
{
    if (right > left)
    {
        int split, next;
        split = left;
        for (next = split + 1; next <= right; next++)
            if (m[left].x < m[next].x)
            {
                split++;
                SWAP(m[next].x, m[split].x);
                SWAP(m[next].y, m[split].y);
            }
        SWAP(m[left].x, m[split].x);
        SWAP(m[left].y, m[split].y);
        my_sort(left, split - 1);
        my_sort(split + 1, right);
    }
}

double result(int n)
{
    double sum;
    int pre_x, pre_y, temp_x, temp_y;

    sum = 0;
    temp_x = pre_x = m[0].x;
    temp_y = pre_y = m[0].y;
    for (int i = 1; i < n; i++)
    {
        if (m[i].y > temp_y)
        {
            int x = pre_x - m[i].x;
            int y = m[i].y - pre_y;
            sum += (double)(m[i].y - temp_y) * sqrt((double)x * x + y * y) / (m[i].y - pre_y);
            temp_x = m[i].x;
            temp_y = m[i].y;
        }
        pre_x = m[i].x;
        pre_y = m[i].y;
    }

    // Verifica se temp_y é igual a 0 e atualiza para 1
    if (temp_y == 0)
    {
        temp_y = 1;
    }

    return sum;
}

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
        printf("%.2f\n", result(n));
    }
    return 0;
}
