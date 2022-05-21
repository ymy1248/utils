#include <bits/stdc++.h>
#include <alias.hpp>

int zeroOneKnapsack(int V, vector<PII> &objs)
{
    int N = objs.size();
    // dp[i][j]: i -> number of objects, j -> volume
    vector<vector<int>> dp(N + 1,vector<int>(V + 1, 0));
    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= V; ++j) {
            if (objs[i].fi > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j- objs[i].fi] + objs[i].se, dp[i-1][j]);
                ans = max(ans, dp[i][j]);
            }
        }
    }
}