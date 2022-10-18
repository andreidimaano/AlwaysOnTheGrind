class Solution {
public:
    int dfs(int r, int c, vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid2.size();
        int m = grid2[0].size();
        int res = 1;
        if(r < 0 || r == n || c < 0 || c == m || grid2[r][c] == 0) {
            return 1;
        }
        grid2[r][c] = 0;
        
        vector<int> dr = {-1,1,0,0};
        vector<int> dc = {0,0,-1,1};
        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            res &= dfs(nr, nc, grid1, grid2);
        }
        
        return res & grid1[r][c];
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        int ans = 0;
        
        for(int r = 0; r < n; r++) {
            for(int c = 0; c < m; c++) {
                if(grid2[r][c] == 1) {
                    ans += dfs(r, c, grid1, grid2);
                }
            }
        }
        return ans;
        
    }
};