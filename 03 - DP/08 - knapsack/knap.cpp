// Recursive : Either include or exclude , at most take an instance at once

int knap(int wt[], int val[], int n, int W) {
    if (n == 0 || W == 0) return 0;
    if (wt[n - 1] > W) {
        return knap(wt, val, n - 1, W);
    } else {
        return max( val[n - 1] + knap(wt, val, n - 1, W - wt[n - 1]) , knap(wt, val, n - 1, W) );
    }
}

// Memo : 

int knap(int wt[], int val[], int n, int W, vector<vector<int>> &dp) {
    if (n == 0 || W == 0) return 0;
    if (dp[n][W] != -1) return dp[n][W];

    if (wt[n - 1] > W) {
        return dp[n][W] = knap(wt, val, n - 1, W, dp);
    } else {
        return dp[n][W] = max( val[n - 1] + knap(wt, val, n - 1, W - wt[n - 1], dp), knap(wt, val, n - 1, W, dp) );
    }
}

int knapsackWithMemoization(int wt[], int val[], int n, int W) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
    return knap(wt, val, n, W, dp);
}

// Tabu : 

int knap(int wt[], int val[], int n, int W) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (wt[i - 1] <= w) {
                dp[i][w] = max(
                    val[i - 1] + dp[i - 1][w - wt[i - 1]],
                    dp[i - 1][w]
                );
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

