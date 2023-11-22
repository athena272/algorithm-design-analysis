#include <stdio.h>

void prefixTable(char *p, int m, int *table)
{
    int len = 0;
    int i = 1;
    table[0] = 0;

    while (i < m)
    {
        if (p[i] == p[len])
        {
            len++;
            table[i] = len;
            i++;
        }
        else
        {
            if (len > 0)
            {
                len = table[len - 1];
            }
            else
            {
                table[i] = 0;
                i++;
            }
        }
    }
}

void searchSubstring(char *s, int n, char *p, int m)
{
    int table[m];
    prefixTable(p, m, table);
    int i = 0;
    int j = 0;
    int found = 0; // Variável para indicar se a substring foi encontrada

    while (i < n)
    {
        if (p[j] == s[i])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            printf("%d\n", i - j);
            j = table[j - 1];
            found = 1; // Substring encontrada
        }
        else if (i < n && p[j] != s[i])
        {
            if (j > 0)
            {
                j = table[j - 1];
            }
            else
            {
                i++;
            }
        }
    }

    if (!found)
    {
        printf("-1\n"); // Substring não encontrada
    }
}

int main()
{
    char s[7000001];
    char p[1000001];

    // Leitura da entrada
    scanf("%s", s);
    scanf("%s", p);

    int n = 0;
    int m = 0;

    while (s[n] != '\0')
    {
        n++;
    }

    while (p[m] != '\0')
    {
        m++;
    }

    // Busca a substring na string e imprime os índices iniciais
    searchSubstring(s, n, p, m);

    return 0;
}
