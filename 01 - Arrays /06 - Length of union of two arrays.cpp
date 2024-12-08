// Push into map + uska size return krdo or mp.size()

class Solution {
  public:
    // Function to return the count of number of elements in union of two arrays.
    int findUnion(vector<int>& a, vector<int>& b) {
        // code here
        
        map<int,int>mp;
        int count = 0 ;
        
        for( int i=0 ; i<a.size() ; i++)
        {
            mp[a[i]]++;
        }
        
        for( int i=0 ; i<b.size() ; i++)
        {
            mp[b[i]]++;
        }
        
        for( auto x : mp)
        {
            count ++;
        }
        
        return count;
    }
};
