// Suppose to return the pair : { mini , maxi }

class Solution {
  public:
    pair<long long, long long> getMinMax(vector<long long int> arr) {
        // code here
        
        int n = arr.size();
        
        long long maxi = INT_MIN;
        long long mini = INT_MAX;
        
        // Maximum
        for( int i=0 ; i<n ; i++)
        {
            if( arr[i] > maxi)
            {
                maxi = arr[i];
            }
        }
        
        // Minimum
        for( int i=0 ; i<n ; i++)
        {
            if( arr[i] < mini)
            {
                mini = arr[i];
            }
        }
        
        return {mini , maxi};
    }
};
