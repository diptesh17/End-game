// A == a , needs to be alphanumeric

class Solution {
public:

    bool isAlphaNum ( char ch) {

        if( ( ch >= '0' && ch <= '9') || ( ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            return true;
        }

        return false;

    }

    bool isPalindrome(string s) {

        int left = 0;
        int right = s.length() - 1;

        while( left < right)
        {
            if( !isAlphaNum(s[left])) {
                left++;
                continue;
            }

            if( !isAlphaNum(s[right])) {
                right--;
                continue;
            }

            if( tolower(s[left]) != tolower(s[right]))
            {
                return false;
            }

            left++;
            right--;
        }

        return true;
        
    }
};
