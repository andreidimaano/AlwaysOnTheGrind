class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int n = mat.size();
        int m = mat[0].size();
        unordered_map<int, vector<int>> diag;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                diag[i+j].push_back(mat[i][j]);
            }
        }
        
        for(int i = 0; i < m + n - 1; i++) {
            if(i % 2 == 0) {
                for(int j = diag[i].size() - 1; j >= 0; j--) {
                    ans.push_back(diag[i][j]);
                }
            } else {
                for(int j = 0; j < diag[i].size(); j++) {
                    ans.push_back(diag[i][j]);
                }
            }
        }
        
        return ans;
    }
};