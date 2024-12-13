// From here onwards variable starting & ending points question based on grid begins

/* Example :
      1
      2 3
      4 5 6
      7 8 9 10
*/

// We can move downwards or diagonally 
// We want to go from top to bottom , but at the end want min path sum to do it 
// If we begin from bottom , we will have 4 recurrense so that's not preferable 
// We have fix starting point , so will begin from it only

// Base case : when we reach last row , add it and there will not be any boundary condition

int solve(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
    int n = triangle.size();
    if (i == n - 1) return triangle[i][j]; // Base case: last row
    if (dp[i][j] != -1) return dp[i][j];  // Memoization

    int down = triangle[i][j] + solve(i + 1, j, triangle, dp);
    int diag = triangle[i][j] + solve(i + 1, j + 1, triangle, dp);

    return dp[i][j] =  min(down, diag);
}

int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solve(0, 0, triangle, dp); // Start from the top
}

// Tabu : 

#include <bits/stdc++.h>
using namespace std;

int minimumPathSum(vector<vector<int> > &triangle, int n) {
    vector<vector<int> > dp(n, vector<int>(n, 0));

    for (int j = 0; j < n; j++) {
        dp[n - 1][j] = triangle[n - 1][j];
    }

    for (int i = n - 2; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            int down = triangle[i][j] + dp[i + 1][j];
            int diagonal = triangle[i][j] + dp[i + 1][j + 1];
            dp[i][j] = min(down, diagonal);
        }
    }

    return dp[0][0];
}

int main() {
    vector<vector<int> > triangle{{1},
                                   {2, 3},
                                   {3, 6, 7},
                                   {8, 9, 6, 10}};
    int n = triangle.size();
    cout << minimumPathSum(triangle, n);
    return 0;
}
