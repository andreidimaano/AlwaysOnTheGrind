class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n = mat.size();
        int m = mat[0].size();
        if(r * c != n * m) return mat;
        
        int row = 0, col = 0;
        int counter = 0;
        vector<vector<int>> newMat(r, vector<int>(c, -1));
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                newMat[i][j] = mat[row][col];
                counter++;
                if(counter == m) {
                    counter = 0;
                    row++;
                    col = 0;
                } else {
                    col++;
                }
            }
        }
        
        return newMat;
    }
};