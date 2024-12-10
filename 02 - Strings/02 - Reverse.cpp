// With reverse() function 

#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    
    cout << "Enter string : " ;
    cin >> str;
    
    reverse( str.begin() , str.end());
    
    cout << "Output string : " << str ;

    return 0;
}

// With 2 ptr

#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    
    cout << "Enter string : " ;
    cin >> str;
    
    int start = 0;
    int end = str.length() - 1;
    
    while( start < end)
    {
        swap( str[start] , str[end] );
        start++;
        end--;
    }
    
    cout << "Output string : " << str ;

    return 0;
}
