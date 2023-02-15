#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct
{
    int x;
    int y;
} Point;

int comp_x(const void *p1, const void *p2)
{
    Point *point1 = (Point *)p1;
    Point *point2 = (Point *)p2;
    return point1->x - point2->x;
}

int comp_y(const void *p1, const void *p2)
{
    Point *point1 = (Point *)p1;
    Point *point2 = (Point *)p2;
    return point1->y - point2->y;
}

double dist(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double closest_pair_helper(Point *points, int n)
{
    if (n <= 3)
    {
        double min_dist = dist(points[0], points[1]);
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                min_dist = MIN(min_dist, dist(points[i], points[j]));
            }
        }
        return min_dist;
    }

    int mid = n / 2;
    double dl = closest_pair_helper(points, mid);
    double dr = closest_pair_helper(points + mid, n - mid);
    double d = MIN(dl, dr);

    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (fabs(points[i].x - points[mid].x) < d)
        {
            strip[j++] = points[i];
        }
    }

    qsort(strip, j, sizeof(Point), comp_y);
    for (int i = 0; i < j - 1; i++)
    {
        for (int k = i + 1; k < j && strip[k].y - strip[i].y < d; k++)
        {
            d = MIN(d, dist(strip[i], strip[k]));
        }
    }

    return d;
}

double closest_pair(Point *points, int n)
{
    qsort(points, n, sizeof(Point), comp_x);
    return closest_pair_helper(points, n);
}

int main()
{
    int n;
    scanf("%d", &n);

    Point points[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    printf("%.4lf\n", closest_pair(points, n));
    return 0;
}