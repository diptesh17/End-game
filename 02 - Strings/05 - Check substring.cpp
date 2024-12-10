#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str = "abababa";
    string sub = "abab";
    

    int pos = str.find(sub);
    
    if( pos == -1)
    {
        cout << "Not found" ;
    }
    else {
        cout << "Found";
    }
}
