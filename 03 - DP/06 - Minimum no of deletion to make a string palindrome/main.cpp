// input : agbcba
// output : 1 ( for abcba , we just need to delete g )

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
    cout << x.length() - ans;
    
    return 0;
}
