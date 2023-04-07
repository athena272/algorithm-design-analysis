#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_NUM 1000

void counting_sort(int arr[], int n)
{
    int i, j;
    int count[MAX_NUM + 1] = {0};

    for (i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    printf("%d", count[0]);
    for (i = 1; i <= MAX_NUM; i++)
    {
        if ((count[i] == 0) && (count[i +1] == 0) && (count[i + 2] == 0)) 
        {
            break;
        }

        printf(" %d", count[i]);
    }
    printf("\n");

    for (i = 1; i <= MAX_NUM; i++)
    {
        count[i] += count[i - 1];
    }

    int output[n];
    for (i = n - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }

    printf("%d", arr[0]);
    for (i = 1; i < n; i++)
    {
        printf(" %d", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n, i;
    int arr[MAX_NUM];

    n = 0;
    while (scanf("%d", &arr[n]) == 1)
    {
        n++;
    }

    counting_sort(arr, n);

    return 0;
}