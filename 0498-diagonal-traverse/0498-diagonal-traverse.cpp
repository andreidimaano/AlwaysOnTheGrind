class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int n = mat.size();
        int m = mat[0].size();
        
        int row = 0;
        int col = 0;
        bool up = true;
        
        while(ans.size() != n * m) {
            if(up) {
                while(row >= 0 && col < m) {
                    ans.push_back(mat[row][col]);
                    row--;
                    col++;
                }
                
                if(col == m) {
                    col--;
                    row += 2;
                } else {
                    row++;
                }
                up = false;
            } else {
                // going down
                while(row < n && col >= 0) {
                    ans.push_back(mat[row][col]);
                    row++;
                    col--;
                }
                
                if(row == n) {
                    row--;
                    col += 2;
                } else {
                    col++;
                }
                up = true;
            }
        }
        
        return ans;
    }
};