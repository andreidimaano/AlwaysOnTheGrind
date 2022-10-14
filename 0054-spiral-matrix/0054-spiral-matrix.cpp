class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left = 0, right = matrix[0].size();
        int top = 0, bottom = matrix.size();
        vector<int> res;
        
        while(left < right && top < bottom) {
            //right
            for(int i = left; i < right; i++) {
                res.push_back(matrix[top][i]);
            }
            top++;
            
            //down
            for(int i = top; i < bottom; i++) {
                res.push_back(matrix[i][right - 1]);
            }
            right--;
            
            //left
            if(top >= bottom) continue;
            for(int i = right - 1; i >= left; i--) {
                res.push_back(matrix[bottom - 1][i]);
            }
            bottom--;
            
            //up
            if(left >= right) continue;
            for(int i = bottom - 1; i >= top; i--) {
                res.push_back(matrix[i][left]);
            }
            left++;
        }
        
        return res;
    }
};