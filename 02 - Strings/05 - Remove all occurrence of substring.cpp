// s.find() => gives starting idx if substring found
// s.erase() => pickup idx , how much length

class Solution {
public:
    string removeOccurrences(string s, string part) {

        while( s.length() > 0 && s.find(part) < s.length())
        {
            // find = start idx
            // erase = delete krdega

            s.erase( s.find(part),part.length());
        }

        return s;
        
    }
};
