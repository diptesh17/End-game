// Frequency of each char : 

#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str = "abababa";
   
    map<char,int>mp;
    
    for( int i=0 ; i<str.length() ; i++)
    {
        mp[str[i]]++;
    }
    
    for( auto x : mp)
    {
        cout << x.first << " " << x.second << endl;
    }
}


// Remove duplicates

#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str = "abababa";
   
    set<char>st;
    
    for( int i=0 ; i<str.length() ; i++)
    {
        st.insert(str[i]);
    }
    
    for( auto x : st)
    {
        cout << x << " ";
    }
}


// Count words 

#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str = "My name is raj";
    int count = 0;
   
    for( int i=0 ; i<str.length() ; i++)
    {
        if( str[i] == ' ')
        {
            count++;
        }
    }
    
    if( count != 0) {
    cout << count+1;
    } else {
        cout << count;
    }
}
