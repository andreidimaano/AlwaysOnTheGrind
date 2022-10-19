class Solution {
public:
    int lengthOfLastWord(string s) {
        int r = s.size() - 1;
        
        while(r >= 0 && s[r] == ' ') {
            r--;
        }
        
        int l = r;
        while(l >= 0 && s[l] != ' ') {
            l--;
        }
        
        // l = beginning - 1
        // r = end
        return r - l;
    }
};