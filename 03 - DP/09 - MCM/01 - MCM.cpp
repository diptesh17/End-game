/* 
  Format of MCM
  - We have string / array as input
  - We take two points , i & j at begin & end
  - We introduce k in between them and divide into i to k && k+1 to j
  - Will store there answer
  - Now change position of k
  - Apply essential function on stored answer & get desire ans

  - i>j , return 0 , base case
  - k begin from i till < j
  - apply func i-k & k+1-j
  - store answer
  - apply max / min based on question
*/

/* 
  - Example : 
  - Arr = { 40 20 30 10 30}
  - Total no of matrix = n - 1 , so there are 4 matrix
  - Dimension are as follows : 
  - A1 = 40 * 20
  - A2 = 20 * 30
  - A3 = 30 * 10
  - A4 = 10 * 30
  - So , arr[i] = arr[i-1] * arr[i] ;
  - So we can't start from 0th idx , will take i at 1

  - Schema to follow : 
  - k = i , k <= j-1 so division => i to k & k+1 to j
*/

// Recursive : 

class Solution {
  public:
  
    int solve(vector<int> &arr , int i , int j)
    {
        // base case : 
        if( i>=j)
        return 0;
        
        int mini = INT_MAX;
        
        // k ka loop
        for(int k = i ; k<=j-1 ; k++)
        {
            int temp = solve(arr,i,k) + solve(arr,k+1,j) + ( arr[i-1] * arr[j] * arr[k] );
            
            if( temp < mini)
            {
                mini = temp;
            }
        }
        
        return mini;
    }
    
    int matrixMultiplication(vector<int> &arr) {
        // code here
        
        int i = 1;
        int j = arr.size() - 1;
        
        int ans = solve( arr , i , j);
        
        return ans;
    }
};

// Memo : 

class Solution {
  public:
    int solve(vector<int> &arr, int i, int j, vector<vector<int>> &dp) {
        // base case
        if (i >= j)
            return 0;

        // check if the result is already computed
        if (dp[i][j] != -1)
            return dp[i][j];

        int mini = INT_MAX;

        // k loop for partitioning
        for (int k = i; k <= j - 1; k++) {
            int temp = solve(arr, i, k, dp) + solve(arr, k + 1, j, dp) + (arr[i - 1] * arr[k] * arr[j]);

            if (temp < mini) {
                mini = temp;
            }
        }

        // store the result in dp table and return
        return dp[i][j] = mini;
    }

    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1)); // Initialize dp table with -1

        int i = 1;
        int j = n - 1;

        return solve(arr, i, j, dp);
    }
};
