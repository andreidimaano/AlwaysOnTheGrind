class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0, r = 0;
        vector<int> res(2, -1);
        int resLength = INT_MAX;
        
        unordered_map<char, int> m;
        for(auto c: t) {
            m[c]++;
        }
        int need = t.size();
        
        for(r; r < s.size(); r++) {
            if(m[s[r]] > 0) {
                need--;
            }
            
            m[s[r]]--;
            while(need == 0) {
                int length = r - l + 1; 
                if(length < resLength) {
                    resLength = length;
                    res[0] = l;
                    res[1] = r;
                }
                m[s[l]]++;
                if(m[s[l]] > 0){
                    need++;
                }
                l++;
            }
        }
        
        
        l = res[0], r = res[1];
        return resLength != INT_MAX ? s.substr(l, r - l + 1) : "";
    }
};