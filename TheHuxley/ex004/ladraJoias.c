#include <stdio.h>
#include <stdlib.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

int main()
{
    int n;
    scanf("%d", &n);

    int *v = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }

    int *dp = (int *)calloc(n, sizeof(int));
    dp[0] = v[0];
    dp[1] = max(v[0], v[1]);
    dp[2] = max(v[1], v[0] + v[2]);

    for (int i = 3; i < n; i++)
    {
        dp[i] = max(max(dp[i - 2], dp[i - 3]) + v[i], dp[i - 1]);
    }

    printf("%d\n", dp[n - 1]);

    free(dp);
    free(v);

    return 0;
}
