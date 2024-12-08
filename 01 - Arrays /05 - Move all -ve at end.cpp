// Imp learning :
// vector<int>ans => .push_back apply
// vector<int>ans(n) => index pe dalna padta hai , direct push nahi hota we get 0 , by default value hai

class Solution {
  public:
    void segregateElements(vector<int>& arr) {
        // Your code goes here
        
        int n = arr.size();
        vector<int>ans;
        
        for( int i=0 ; i<n ; i++)
        {
            if( arr[i] >= 0)
            {
                ans.push_back(arr[i]);
            }
        }
        
         for( int i=0 ; i<n ; i++)
        {
            if( arr[i] < 0)
            {
                ans.push_back(arr[i]);
            }
        }
        
         for( int i=0 ; i<n ; i++)
        {
            arr[i] = ans[i];
        }
    }
};
