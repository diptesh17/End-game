// Sort + pick first & last , get min length ans start matching and return substring from 0 till matching idx

class Solution {
public:
    string longestCommonPrefix(vector<string>& arr) {

        sort( arr.begin() , arr.end());

        string first = arr.front();
        string last = arr.back();
        int minLength = min(first.size(), last.size());

        int i = 0;

        while (i < minLength && first[i] == last[i])
        {
            i++;
        }

        return first.substr(0, i);
        
    }
};
