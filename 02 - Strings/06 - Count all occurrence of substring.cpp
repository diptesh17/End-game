#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str = "abababa";
    string sub = "aba";
    int count = 0; 
    int pos = 0; 

    while (pos < str.length()) {
        pos = str.find(sub, pos); 
        if (pos == -1) {      
            break;
        }
        count++;                
        pos++;                  
    }

    cout <<  count;
}
