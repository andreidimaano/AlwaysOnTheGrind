class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int l = 0, r = matrix.size() - 1;
        while(l < r) {
            for(int i = 0; i < r - l; i++) {
                int top = l, bot = r;
                
                int topLeft = matrix[top][l + i];
                // bl to tl
                matrix[top][l + i] = matrix[bot - i][l];
                // br to bl
                matrix[bot - i][l] = matrix[bot][r-i];
                // tr to br
                matrix[bot][r - i] = matrix[top+i][r];
                // tl to tr
                matrix[top+i][r] = topLeft;
                
            }
            l++; r--;
        }
    }
};