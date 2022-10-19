class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
    
        for(int i = 2; i <= numRows; i++) {
            int count = i;
            vector<int> curr(count, 1);
            vector<int> prev = ans[i - 2];
            for(int j = 1; j < count - 1; j++) {
                curr[j] = prev[j - 1] + prev[j];
            }
            ans.push_back(curr);
        }
        
        
        return ans;
    }
};