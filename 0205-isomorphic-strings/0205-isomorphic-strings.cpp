class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> st, ts;
        
        for(int i =0; i < s.size(); i++) {
            char c1 = s[i], c2 = t[i];
            
            if(st.find(c1) != st.end() && st[c1] != c2 || 
                ts.find(c2) != ts.end() && ts[c2] != c1
              ) {
                return false;
            }
            
            st[c1] = c2;
            ts[c2] = c1;
        }
            
        return true;
    }
};