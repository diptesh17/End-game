class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size();

        vector<int>dp(n+1);

        // base case
        dp[0] = 0;
        dp[1] = 0;

        for( int i=2 ; i<=n ; i++)
        {
            // n-1 => cost of prev + min cost till prev
            int option1 = cost[i-1] + dp[i-1];

            // n-2 => -//-
            int option2 = cost[i-2] + dp[i-2];

            dp[i] = min(option1 , option2);
        }

        return dp[n];
        
    }
};
