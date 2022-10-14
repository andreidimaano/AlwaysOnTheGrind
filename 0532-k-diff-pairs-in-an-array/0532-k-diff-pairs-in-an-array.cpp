class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> m;
        
         for(auto i: nums) {
            m[i]++;
        }
        
        for(auto i: m) {
            if(m.find((k - i.first) * -1) != m.end()) {
                if((k - i.first) * -1 == i.first && m[(k - i.first) * -1] == 1) continue;
                ans++;
                m[(k - i.first) * -1]--;
            }
        }
        
        return ans;
    }
};