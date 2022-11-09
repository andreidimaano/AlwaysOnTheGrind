class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int ans = 0;
        
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) { return a[0] < b[0];});
        
        for(int i = 0; i < n-1; i++) {
            if(intervals[i][1] > intervals[i + 1][0]) {
                if(intervals[i][1] < intervals[i+1][1]){
                    intervals[i+1] = intervals[i];
                }
                ans++;
            }
        }
        
        
        return ans;
    }
};