// geek & eke => geeke , which consist of both
// Simple logic is to find lcs and remove one of lcs's length from amswer
// Answer = n + m - Length of LCS

#include<bits/stdc++.h>
using namespace std;

int LCS( string x , string y , int n , int m)
{
    
    int dp[n+1][m+1];
    
    // base case to initialization
    for( int i=0 ; i<=n ; i++)
    {
        for( int j=0 ; j<=m ; j++)
        {
            if( i ==0 || j == 0 )
            {
                dp[i][j] = 0;
            }
        }
    }
    
    // Choice diagram 
    
    for( int i=1 ; i<=n ; i++)
    {
        for( int j=1 ; j<=m ; j++)
        {
            if( x[i-1] == y[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    
    return dp[n][m];
    
}

int main() {
    
    string x;
    string y;
    
    cin >> x >> y;

    // Just here is the change from LCS
    int ans = x.length() + y.length() - LCS(x,y,x.length() , y.length());
    
    cout << ans;
    
    return 0;
}
