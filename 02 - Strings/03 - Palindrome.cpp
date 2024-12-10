// With 2 ptr : 

class Solution {
  public:
    // Function to check if a string is a palindrome.
    bool isPalindrome(string& s) {
        // code here
        
        int left = 0;
        int right = s.length() - 1;
        
        while( left < right )
        {
            if( s[left] == s[right])
            {
                left++;
                right--;
            }
            else {
                return false;
            }
        }
        
        return true;
    }
};
