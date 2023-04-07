#include <stdio.h>
#include <string.h>

int main()
{
    char text[100], substring[100];
    int i, j, found;

    printf("Enter text: ");
    fgets(text, 100, stdin);

    printf("Enter substring: ");
    fgets(substring, 100, stdin);

    int n = strlen(text);
    int m = strlen(substring);

    for (i = 0; i <= n - m; i++)
    {
        found = 1;
        for (j = 0; j < m; j++)
        {
            if (text[i + j] != substring[j])
            {
                found = 0;
                break;
            }
        }
        if (found == 1)
        {
            printf("Substring found at index %d\n", i);
        }
    }
    return 0;
}
