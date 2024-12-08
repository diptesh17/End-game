// Brute : fails at one test case only

class Solution {
  public:
    // Complete this function
    // Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(vector<int>& arr) {
        // Your code here
        
        int sum = 0;
        
        for( int i=0 ; i<arr.size() ; i++)
        {
            for( int j=i ; j<arr.size() ; j++)
            {
                sum += arr[j];
                
                if( sum == 0)
                {
                    return true;
                }
            }
            
            sum = 0;
        }
        
        return false;
    }
};


// Optimal : x tak ka sum p1 hai ..... aage jake ........ y pr sum p1 aya , means bichme 0 pakka hoga , use hash to store it

class Solution {
  public:
    // Complete this function
    // Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(vector<int>& arr) {
        // Your code here
        
        int sum = 0;
        set<int>st;
        
        for( int i=0 ; i<arr.size() ; i++)
        {
            sum += arr[i];
            
            if( sum ==0 || st.find(sum) != st.end())
            {
                return true;
            }
            
            st.insert(sum);
        }
        
        return false;
    }
};
