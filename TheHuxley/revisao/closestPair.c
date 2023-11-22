#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdlib.h>

typedef struct Point
{
    double x;
    double y;
} Point;

// Function to compare two points for sorting
int compare_points(const void *a, const void *b)
{
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;
    if (p1->x < p2->x)
    {
        return -1;
    }
    else if (p1->x > p2->x)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Function to swap two points
void swap_points(Point *p1, Point *p2)
{
    Point temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

// Function to perform quicksort on an array of points
void my_qsort(Point points[], int low, int high)
{
    if (low < high)
    {
        int pivot_index = low;
        Point pivot = points[pivot_index];
        int i = low + 1;
        int j = high;

        while (i <= j)
        {
            if (compare_points(&points[i], &pivot) <= 0)
            {
                i++;
            }
            else if (compare_points(&points[j], &pivot) > 0)
            {
                j--;
            }
            else
            {
                swap_points(&points[i], &points[j]);
            }
        }

        swap_points(&points[pivot_index], &points[j]);

        my_qsort(points, low, j - 1);
        my_qsort(points, j + 1, high);
    }
}

// Function to calculate the distance between two points
double distance(Point p1, Point p2)
{
    return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
}

// Function to find the closest pair of points
double closest_pair(Point points[], int n)
{
    my_qsort(points, 0, n - 1);

    double min_dist = DBL_MAX;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < fmin(i + 7, n); j++)
        {
            double dist = distance(points[i], points[j]);
            if (dist < min_dist)
            {
                min_dist = dist;
            }
        }
    }

    return min_dist;
}

// Main function
int main()
{
    while (1)
    {
        int n;
        scanf("%d", &n);
        if (n == 0)
        {
            break;
        }
        Point points[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%lf %lf", &points[i].x, &points[i].y);
        }
        double min_dist = closest_pair(points, n);
        if (min_dist >= 10000)
        {
            printf("INFINITY\n");
        }
        else
        {
            printf("%.4lf\n", min_dist);
        }
    }

    return 0;
}
