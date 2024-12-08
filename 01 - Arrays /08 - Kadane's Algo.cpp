// VVV IMP
// Also called Max Sum Subarray
// Array elem = n , then subarray => n * ( n+1) / 2

class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int> &arr) {
        // code here...
        
        int sum = 0;
        int maxi = INT_MIN;
        
        for( int x : arr)
        {
            sum += x;
            maxi = max( sum , maxi);
            
            if( sum < 0)
            {
                sum = 0;
            }
        }
        
        return maxi;
    }
};
