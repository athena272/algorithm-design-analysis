#include <stdio.h>

int binarySearch(int list[], int key, int size)
{
    int start = 0;
    int end = size - 1;
    while (start <= end)
    {
        int middle = (start + end) / 2;
        if (list[middle] == key)
        {
            return middle;
        }
        else if (list[middle] > key)
        {
            end = middle - 1;
        }
        else
        {
            start = middle + 1;
        }
    }
    return -1;
}

int main()
{
    int cases;
    scanf("%d", &cases);
    int cpfList[cases];
    int scoreList[cases];
    for (int i = 0; i < cases; i++)
    {
        scanf("%d", &cpfList[i]);
    }
    for (int i = 0; i < cases; i++)
    {
        scanf("%d", &scoreList[i]);
    }
    int testCases;
    scanf("%d", &testCases);
    for (int i = 0; i < testCases; i++)
    {
        int cpf;
        scanf("%d", &cpf);
        int position = binarySearch(cpfList, cpf, cases);
        if (position >= 0)
        {
            printf("%d\n", scoreList[position]);
        }
        else
        {
            printf("NAO SE APRESENTOU\n");
        }
    }
    return 0;
}
