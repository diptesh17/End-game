// Sort + return k - 1 , because of 0 based indexing

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        
        sort( arr.begin() , arr.end());
        
        return arr[k-1];
    }
};
