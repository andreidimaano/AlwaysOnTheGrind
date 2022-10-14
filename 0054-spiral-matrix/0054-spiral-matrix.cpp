class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int l = 0, r = matrix[0].size() -1;
        int t = 0, b = matrix.size() -1;
            
        vector<int> res;
        while(l <= r && t <= b) {
            // right
            for(int i = l; i <= r; i++) {
                res.push_back(matrix[t][i]);
            }
            t++;
            
            // bot
            for(int i = t; i <= b; i++) {
                res.push_back(matrix[i][r]);
            }
            r--;
            
            if(t <= b && l <= r) {
                // left
                for(int i = r; i >= l; i--) {
                    res.push_back(matrix[b][i]);
                }
                b--;
                // up   
                for(int i = b; i >= t; i--) {
                    res.push_back(matrix[i][l]);
                }
                l++;
            }
        }
        
        return res;
    }
};