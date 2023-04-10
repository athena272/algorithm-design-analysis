#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdlib.h>

typedef struct Point {
    double x;
    double y;
} Point;

// Function to compare two points for sorting
int compare_points(const void* a, const void* b) {
    Point* p1 = (Point*)a;
    Point* p2 = (Point*)b;
    if (p1->x < p2->x) {
        return -1;
    } else if (p1->x > p2->x) {
        return 1;
    } else {
        return 0;
    }
}

// Function to calculate the distance between two points
double distance(Point p1, Point p2) {
    return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
}

// Function to find the closest pair of points
double closest_pair(Point points[], int n) {
    qsort(points, n, sizeof(Point), compare_points);

    double min_dist = DBL_MAX;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < fmin(i + 7, n); j++) {
            double dist = distance(points[i], points[j]);
            if (dist < min_dist) {
                min_dist = dist;
            }
        }
    }

    return min_dist;
}

// Main function
int main() {
    while (1) {
        int n;
        scanf("%d", &n);
        if (n == 0) {
            break;
        }
        Point points[n];
        for (int i = 0; i < n; i++) {
            scanf("%lf %lf", &points[i].x, &points[i].y);
        }
        double min_dist = closest_pair(points, n);
        if (min_dist >= 10000) {
            printf("INFINITY\n");
        } else {
            printf("%.4lf\n", min_dist);
        }
    }

    return 0;
}
