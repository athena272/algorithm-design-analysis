#include <stdio.h>
#include <math.h>

int main()
{
    int q, n;
    double a;

    scanf("%d", &q);

    while (q--)
    { // enquanto houver consultas
        scanf("%lf %d", &a, &n);

        double l = 0, r = a, m, b;

        while (fabs(r - l) >= pow(10, -6))
        {                    // enquanto a precisão não for alcançada
            m = (l + r) / 2; // ponto médio do intervalo
            b = pow(m, n);   // valor do chute atual

            if (b < a)
            {
                l = m; // atualiza o limite inferior do intervalo
            }
            else
            {
                r = m; // atualiza o limite superior do intervalo
            }
        }

        printf("%.1lf\n", m); // imprime o resultado com uma casa decimal
    }

    return 0;
}
