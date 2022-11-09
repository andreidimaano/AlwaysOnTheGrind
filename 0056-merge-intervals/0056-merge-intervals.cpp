class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
           return a[0] < b[0]; 
        });
        
        vector<vector<int>> ans;
        
        vector<int> currInterval = intervals[0];
        for(int i = 1; i < intervals.size(); i++) {
            // merge
            if(intervals[i][0] <= currInterval[1]) {
                currInterval[1] =  max(intervals[i][1], currInterval[1]);
            } else {
                ans.push_back(currInterval);
                currInterval = intervals[i];
            }
        }
        
        ans.push_back(currInterval);
        
        return ans;
    }
};