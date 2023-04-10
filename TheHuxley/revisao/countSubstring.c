#include <stdio.h>
#include <stdlib.h> // Inclusão do cabeçalho para usar malloc e free
#include <string.h>

void get_lps(char *pattern, int m, int *lps)
{
    int len = 0;
    int i = 1;
    lps[0] = 0;

    while (i < m)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void kmp_search(char *text, char *pattern)
{
    int n = strlen(text);
    int m = strlen(pattern);

    int *lps = (int *)malloc(sizeof(int) * m);
    get_lps(pattern, m, lps);

    int i = 0;
    int j = 0;

    while (i < n)
    {
        if (text[i] == pattern[j])
        {
            i++;
            j++;
        }

        if (j == m)
        {
            printf("%d\n", i - j);
            j = lps[j - 1];
        }
        else if (i < n && text[i] != pattern[j])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }

    free(lps);
}

int main()
{
    char text[2000001];
    char pattern[2000001];

    // Leitura da entrada
    scanf("%s", text);
    scanf("%s", pattern);

    // Busca de substring utilizando o algoritmo KMP
    kmp_search(text, pattern);

    return 0;
}
