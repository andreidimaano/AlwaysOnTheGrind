class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n = mat.size();
        int m = mat[0].size();
        if(r * c != n * m) return mat;
        
        queue<int> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                q.push(mat[i][j]);
            }
        }
        
        vector<vector<int>> newMat(r, vector<int>(c, -1));
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                newMat[i][j] = q.front(); q.pop();
            }
        }
        
        return newMat;
    }
};