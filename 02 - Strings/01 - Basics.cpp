// Char array : 

#include <bits/stdc++.h>
using namespace std;

int main()
{
    char str[100];
    
    cout << "Enter char array : " ;
    cin.getline(str,100,'_');
    
    cout << "Output array : " << str ;

    return 0;
}

// input : PQR_400
// output : PQR

// with only cin >> str
// input : hello world
// output : hello

// Strings : Adv char arrays

// string : dynamic => runtime resize
// char array : static 

// Length : str.length()


#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    
    cout << "Enter string : " ;
    getline(cin,str);
    
    cout << "Output string : " << str ;

    return 0;
}

// input : Hello World
// output : Hello World

// With plain cin >> str => output = Hello






