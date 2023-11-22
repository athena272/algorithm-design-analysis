#include <stdio.h>
#include <string.h>

#define MAX_N 1000

int dp[MAX_N][MAX_N];

int max(int a, int b)
{
    return a > b ? a : b;
}

int is_palindrome(char *str, int l, int r)
{
    while (l < r)
    {
        if (str[l] != str[r])
        {
            return 0;
        }
        l++;
        r--;
    }
    return 1;
}

int max_palindrome(char *str, int n)
{
    memset(dp, 0, sizeof(dp)); // Inicializa a matriz de memoização com 0
    for (int len = 1; len <= n; len++)
    {
        for (int i = 0; i + len - 1 < n; i++)
        {
            int j = i + len - 1;
            if (is_palindrome(str, i, j))
            { // Caso base: substring já é um palíndromo
                dp[i][j] = len;
            }
            else
            {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]); // Remove um caractere e verifica se a substring restante é um palíndromo
            }
        }
    }
    return dp[0][n - 1];
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        char str[MAX_N];
        scanf("%s", str);
        int n = strlen(str);
        printf("%d\n", max_palindrome(str, n));
    }
    return 0;
}
