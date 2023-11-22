#include <stdio.h>
#include <string.h>

#define MAX_N 1010
#define MAX_G 110
#define MAX_W 31

int n, g, p[MAX_N], w[MAX_N], mw[MAX_G], dp[MAX_G][MAX_W];

int max(int a, int b)
{
    return a > b ? a : b;
}

int solve()
{
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= mw[1]; j++)
        {
            dp[1][j] = j >= w[i] ? p[i] : 0;
        }

        for (int j = 2; j <= g; j++)
        {
            for (int k = 0; k <= mw[j]; k++)
            {
                dp[j][k] = dp[j - 1][k];

                if (k >= w[i])
                {
                    dp[j][k] = max(dp[j][k], dp[j - 1][k - w[i]] + p[i]);
                }
            }
        }
    }

    return dp[g][mw[g]];
}

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        scanf("%d", &n);

        for (int i = 1; i <= n; i++)
        {
            scanf("%d %d", &p[i], &w[i]);
        }

        scanf("%d", &g);

        for (int i = 1; i <= g; i++)
        {
            scanf("%d", &mw[i]);
        }

        int ans = 0;

        for (int i = 1; i <= g; i++)
        {
            ans += solve();
        }

        printf("%d\n", ans);
    }

    return 0;
}
