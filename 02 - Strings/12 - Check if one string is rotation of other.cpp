// string::npos : indicates "no position" or "not found"

#include <iostream>
#include <string>
using namespace std;

bool isRotation(string s1, string s2) {
    // If lengths are different, s2 cannot be a rotation of s1
    if (s1.length() != s2.length()) return false;

    // Concatenate s1 with itself
    string temp = s1 + s1;

    // Check if s2 is a substring of temp
    return (temp.find(s2) != string::npos);
}

int main() {
    string s1 = "abcde";
    string s2 = "cdeab";

    if (isRotation(s1, s2)) {
        cout << s2 << " is a rotation of " << s1 << endl;
    } else {
        cout << s2 << " is not a rotation of " << s1 << endl;
    }

    return 0;
}
