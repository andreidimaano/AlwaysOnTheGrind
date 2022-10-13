class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size()) return false;
        
        unordered_map<char, int> m;
        
        for(int i = 0; i < s1.size(); i++) {
            m[s1[i]]++;
            m[s2[i]]--;
        }
        
        if(allZero(m)) return true;
        
        for(int i = s1.size(); i < s2.size(); i++) {
            m[s2[i]]--;
            m[s2[i - s1.size()]]++;
            if(allZero(m)) return true;
        }
        
        
        return false;
    }
    
    bool allZero(unordered_map<char, int> m) {
        for(auto pair: m) {
            if(pair.second != 0) {
                return false;
            }
        }
            
        return true;
    }
};