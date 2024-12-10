#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str1 = "abababa";
    string str2 = "babaaba";
    
    sort( str1.begin() , str1.end());
    sort( str2.begin() , str2.end());
    
    if( str1 == str2)
    {
        cout << "Anagrams" ;
    } else {
        cout << " Non Anagrams";
    }
}
