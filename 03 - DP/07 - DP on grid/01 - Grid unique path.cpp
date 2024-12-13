/* 
  How to write recurense for 2D grid
  - Express in term of idx (i,j)
  - Explore all stuffs
  - Do sum / max / min based on question
*/

// Memoization : Going from bottom to up ( m-1 & n-1 to 0 , 0)
// We can go in two ways up or left from bottom

#include <bits/stdc++.h>
using namespace std;

int countWaysUtil(int i, int j, vector<vector<int>>& dp) {
    if (i == 0 && j == 0)
        return 1;

    if (i < 0 || j < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int up = countWaysUtil(i - 1, j, dp);
    int left = countWaysUtil(i, j - 1, dp);

    return dp[i][j] = up + left;
}

int main() {
    int m = 3, n = 2;

    // Create dp table in main function
    vector<vector<int>> dp(m, vector<int>(n, -1));

    // Calculate the number of ways using dp
    int result = countWaysUtil(m - 1, n - 1, dp);

    cout << "Number of ways to reach (" << m - 1 << ", " << n - 1 << "): " << result << endl;
    return 0;
}


/* 
  Steps for Tabulaion 
  - Declare base cases
  - Express all states in for loop
  - Copy the recurrence & write
*/

#include <bits/stdc++.h>
using namespace std;

int countWaysUtil(int m, int n, vector<vector<int>>& dp) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = 1;
                continue;
            }
            int up = 0, left = 0;
            if (i > 0) up = dp[i - 1][j];
            if (j > 0) left = dp[i][j - 1];
            dp[i][j] = up + left;
        }
    }
    return dp[m - 1][n - 1];
}

int main() {
    int m = 3, n = 2;
    vector<vector<int>> dp(m, vector<int>(n, -1));
    cout << countWaysUtil(m, n, dp) << endl;
    return 0;
}
