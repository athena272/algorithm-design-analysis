#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

typedef struct
{
    int n;
    int *elements;
} t_vector;

t_vector repetidas(t_vector album, t_vector novas)
{
    int i, j;
    int k = 0;
    t_vector reps;

    if (album.n < novas.n)
        reps.n = album.n;
    else
        reps.n = novas.n;

    reps.elements = (int *)malloc((reps.n + 1) * sizeof(int));

    for (i = 0; i < album.n; i++)
    {
        for (j = i; j < novas.n; j++)
        {
            if (album.elements[i] == novas.elements[j])
            {

                reps.elements[k] = album.elements[i];
                reps.n = k++;
                k++;
            }
        }
    }

    reps.elements[i] = INT_MAX;

    return reps;
}

int main()
{
    int i, k;
    t_vector album, novas, reps;
    scanf("%d", &album.n);
    album.elements = (int *)malloc((album.n + 1) * sizeof(int));
    for (i = 0; i < album.n; i++)
    {
        scanf("%d", &(album.elements[i]));
    }
    album.elements[i] = INT_MAX;

    scanf("%d", &novas.n);
    novas.elements = (int *)malloc((novas.n + 1) * sizeof(int));
    for (i = 0; i < novas.n; i++)
    {
        scanf("%d", &(novas.elements[i]));
    }
    novas.elements[i] = INT_MAX;

    reps = repetidas(album, novas);

    for (k = 0; k < reps.n - 1; k++)
        printf("%d ", reps.elements[k]);
    printf("%d\n", reps.elements[k]);

    free(reps.elements);
    free(album.elements);
    free(novas.elements);

    return 0;
}