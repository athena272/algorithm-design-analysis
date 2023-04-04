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

        double b = a / n;               // chute inicial
        double precision = pow(10, -6); // precisão requerida

        while (fabs(a - pow(b, n)) > precision)
        {                                              // enquanto a precisão não for alcançada
            b = ((n - 1) * b + a / pow(b, n - 1)) / n; // aplicação da fórmula de Newton-Raphson
        }

        printf("%.1lf\n", b); // imprime o resultado com uma casa decimal
    }

    return 0;
}
