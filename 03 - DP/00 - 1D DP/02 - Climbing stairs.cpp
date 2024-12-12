// For reaching the nth stair , how many ways are there and at instance we can take 1 or 2 steps

// nth step pe jump keliyee , i-1 & i-2 se hi le saktee
// 0th step = 1 && 1st step = 1
// rest will manage

class Solution {
public:
    int climbStairs(int n) {

        vector<int>dp(n+1);

        dp[0] = 1;
        dp[1] = 1;

        for( int i=2 ; i<=n ; i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
        
    }
};
