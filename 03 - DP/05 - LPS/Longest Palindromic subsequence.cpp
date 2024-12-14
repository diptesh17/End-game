// In LCS we have 2 strings , in LPS we have only one string so kindly reverse original string and take it as a second string for LCS
// input => agbcba
// output => 5 ( abcba )

// str 1 : agbcba
// str 2 : abcbga
// LCS : abcba , woahh thats the answer

#include <bits/stdc++.h>
using namespace std;

int LCS( string x , string y , int n , int m)
{
    if( n == 0 || m == 0)
    {
        return 0;
    }
    
    if( x[n-1] == y[m-1])
    {
        return 1 + LCS(x,y,n-1,m-1);
    } else {
        return max( ( LCS(x,y,n-1,m) ) , ( LCS(x,y,n,m-1) ) );
    }
}

int main()
{
    
    string x;
    cin >> x ;
    
    // second string :
    string y = x;
    reverse(y.begin() , y.end());
    
    int ans = LCS( x,y,x.length() , y.length());
    cout << ans;
    
    return 0;
}
