class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minsize = INT_MAX;
        
        for(auto s: strs) {
            minsize = min((int)s.size(), minsize);
        }
        
        string ans = "";
        for(int i = 0; i < minsize; i++) {
            char c = strs[0][i];
            for(auto s: strs) {
                if(s[i] != c) {
                    return ans;
                }
            }
            ans += c;
        }
        
        return ans;
    }
};