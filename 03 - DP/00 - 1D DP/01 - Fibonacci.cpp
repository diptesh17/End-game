// Rec + Memo are easyy 

// Tabulation : This is how we can convert recursion to tabulation

int solve( int n)
{
    // step 1 : dp array
    int dp[n+1];
    
    // step 2 : Initi
    dp[0] = 0;
    dp[1] = 1;
    
    // step 3 : loop + logic
    for( int i=2 ; i<=n ; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    return dp[n];

    
}

// Space optimization : 

int solve( int n)
{
    int prev1 = 1;
    int prev2 = 0;
    int curr;
    
    for( int i=2 ; i<=n ; i++)
    {
        int ans = prev1 + prev2;
        curr = ans;
        prev2 = prev1;
        prev1 = curr;
    }
    
    return prev1;

    
}

int main() {
    
    int ans = solve(6);
    cout << ans;
}

int main() {
    
    int ans = solve(6);
    cout << ans;
}
