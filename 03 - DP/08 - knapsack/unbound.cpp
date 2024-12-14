// Unbounded knapsack : An instance can be pickup for multiple time 

// Recursive : 

long unboundknap(int wt[], int val[], int n, int W) {
    if (n == 0 || W == 0) return 0;
    if (wt[n - 1] <= W) 
        return max(val[n - 1] + unboundknap(wt, val, n, W - wt[n - 1]), unboundknap(wt, val, n - 1, W));
    else 
        return unboundknap(wt, val, n - 1, W);
}

// Memo : 

long unboundknapMemo(int wt[], int val[], int n, int W, vector<vector<long>> &dp) {
    if (n == 0 || W == 0) return 0;
    if (dp[n][W] != -1) return dp[n][W];
    if (wt[n - 1] <= W) 
        return dp[n][W] = max(val[n - 1] + unboundknapMemo(wt, val, n, W - wt[n - 1], dp), unboundknapMemo(wt, val, n - 1, W, dp));
    else 
        return dp[n][W] = unboundknapMemo(wt, val, n - 1, W, dp);
}

long unboundknap(int wt[], int val[], int n, int W) {
    vector<vector<long>> dp(n + 1, vector<long>(W + 1, -1));
    return unboundknapMemo(wt, val, n, W, dp);
}

// knap : 

#include <vector>
using namespace std;

long unboundknap(int wt[], int val[], int n, int W) {
    vector<long> dp(W + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int w = wt[i]; w <= W; w++) {
            dp[w] = max(dp[w], dp[w - wt[i]] + val[i]);
        }
    }
    return dp[W];
}

