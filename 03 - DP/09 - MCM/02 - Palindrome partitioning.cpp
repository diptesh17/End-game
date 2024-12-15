/*
  - Ex : nitin
  - We want to divide string into min no of partition so that every partition must be palindrome
  - output : 2 
  - n | iti | n
  - Here we had added two partition in between

  - How to identify its MCM
  - we fix start & end
  - then we are partitioning in all in between position like k in MCM

  - Steps : 
  - Find i,j
  - base case
  - k loop
  - apply function on temp ans , to find actual ans

  - Logic : 
  - we take begin from i=0 to j=s.length() - 1
  - IF empty string or string length is one then we dont need to do any kind of partition , so return 0
  - is entire string is palindrome then also return 0
*/

// Recursive : 

class Solution {
  public:
    bool isPalindrome(string &s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    int solve(string &s, int i, int j) {
        if (i >= j || isPalindrome(s, i, j))
            return 0;

        int mini = INT_MAX;

        for (int k = i; k < j; k++) {
            int temp = solve(s, i, k) + solve(s, k + 1, j) + 1;

            mini = min(mini, temp);
        }

        return mini;
    }

    int palindromicPartition(string &s) {
        return solve(s, 0, s.length() - 1);
    }
};


// Memo : 

class Solution {
  public:
    bool isPalindrome(string &s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    int solve(string &s, int i, int j, vector<vector<int>> &dp) {
        if (i >= j || isPalindrome(s, i, j))
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int mini = INT_MAX;

        for (int k = i; k < j; k++) {
            int temp = solve(s, i, k, dp) + solve(s, k + 1, j, dp) + 1;

            mini = min(mini, temp);
        }

        return dp[i][j] = mini;
    }

    int palindromicPartition(string &s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1)); 
        return solve(s, 0, n - 1, dp);
    }
};

// Optional : 


class Solution {
    public :
     bool isPalindrome (string & s, int i, int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++; j--;
        }
        return true;
    }
    

    int solve (string & s, int i, int j, vector<int> & dp){    
        
        if(i>=j or isPalindrome(s, i, j)) return 0;
        
        if(dp[i]!=-1) return dp[i];
        
        int ans = INT_MAX;
        
        for(int k=i; k<j; k++){
            
            /* 
                Instead of writing below standard line
                We will recurse for only right part
                Only when left part turns out to be palindrome
				
				Reason : If left substring becomes palindrome then there is no need to partition it further 
				(which in turn reduces the number of recursive calls)
                
                int temp =  solve (s, i, k, dp, palindrome) + solve (s, k+1, j, dp, palindrome) + 1;
                
            */
            
            if(isPalindrome(s, i, k)){                         
                int temp = solve (s, k+1, j, dp) + 1;
                ans = min (ans, temp);
            }
        }
        
        return dp[i] = ans;
    }
    
    int palindromicPartition(string &s) {
        int n = s.length();
        
        /* I've used 1D DP here becoz only one parameter is changing i.e. `i` */
        
        vector<int> dp (n+1, -1);   
            
        return solve (s, 0, n-1, dp);
    }
};
