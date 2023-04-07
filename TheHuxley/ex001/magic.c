#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100

// Define uma estrutura para representar um ponto com coordenadas (x, y)
typedef struct
{
    double x;
    double y;
} Point;

// Define uma estrutura para representar um triângulo com três pontos
typedef struct
{
    Point p1;
    Point p2;
    Point p3;
} Triangle;

// Função para calcular a área de um triângulo dado três pontos
double area(Point a, Point b, Point c)
{
    return fabs((a.x - c.x) * (b.y - c.y) - (b.x - c.x) * (a.y - c.y)) / 2.0;
}

// Função para verificar se um ponto está dentro de um triângulo
int is_inside_triangle(Point p, Triangle t)
{
    double a = area(t.p1, t.p2, t.p3);
    double a1 = area(p, t.p1, t.p2);
    double a2 = area(p, t.p2, t.p3);
    double a3 = area(p, t.p3, t.p1);
    return fabs(a - (a1 + a2 + a3)) < 1e-6;
}

// Função para verificar se existem cinco pontos que formam um pentágono convexo
int find_magic_pentagon(Point *points, int n)
{
    int i, j, k, l;
    for (i = 0; i < n - 4; i++)
    {
        for (j = i + 1; j < n - 3; j++)
        {
            // Encontra o triângulo mais à direita com os pontos i e j
            Triangle right_triangle = {points[i], points[j], points[i]};
            for (k = 0; k < n; k++)
            {
                if (k != i && k != j)
                {
                    double a = area(points[i], points[j], points[k]);
                    double b = area(right_triangle.p1, right_triangle.p2, points[k]);
                    if (a > 0 && b > 0 && a < b)
                    {
                        right_triangle.p3 = points[k];
                    }
                }
            }
            // Verifica se os outros dois pontos estão dentro do triângulo mais à direita
            for (l = 0; l < n; l++)
            {
                if (l != i && l != j && l != right_triangle.p3)
                {
                    if (is_inside_triangle(points[l], right_triangle))
                    {
                        for (k = 0; k < n; k++)
                        {
                            if (k != i && k != j && k != l && k != right_triangle.p3)
                            {
                                if (is_inside_triangle(points[k], right_triangle))
                                {
                                    return 1; // encontrou um pentágono convexo que contém todos os pontos
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0; // não encontrou um pentágono convexo que contém todos os pontos
}

int main()
{
    int n, i;
    Point points[MAX_POINTS];
    // Lê o número de pontos e as coordenadas dos pontos
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }
    // Verifica se existe um pentágono convexo que contém todos os pontos dados
    if (find_magic_pentagon(points, n))
    {
        printf("pentagono magico!\n");
    }
    else
    {
        printf("cade a magia?\n");
    }

    return 0;
}