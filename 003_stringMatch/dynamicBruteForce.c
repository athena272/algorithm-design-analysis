#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int substring_search(char *text, char *substring)
{
    int n = strlen(text);
    int m = strlen(substring);
    for (int i = 0; i <= n - m; i++)
    {
        int j;
        for (j = 0; j < m; j++)
        {
            if (text[i + j] != substring[j])
            {
                break;
            }
        }
        if (j == m)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    char *text = NULL;
    char *substring = NULL;
    size_t text_size = 0, substring_size = 0;

    printf("Enter text: ");
    getline(&text, &text_size, stdin);
    printf("Enter substring to search: ");
    getline(&substring, &substring_size, stdin);

    int index = substring_search(text, substring);

    if (index == -1)
    {
        printf("Substring not found in text\n");
    }
    else
    {
        printf("Substring found at index %d\n", index);
    }

    free(text);
    free(substring);

    return 0;
}
