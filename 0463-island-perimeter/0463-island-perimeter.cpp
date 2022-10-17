class Solution {
public:
    bool valid(int r, int c, int n, int m) {
        return (0 <= r && r < n && 0 <= c && c < m);
    }
    
    int dfs(int r, int c, vector<vector<int>> &grid, vector<vector<bool>>& vis) {
        vis[r][c] = true;
        int n = grid.size();
        int m = grid[0].size();
        vector<int> dr = {-1,1,0,0};
        vector<int> dc = {0,0,-1,1};
        
        int count = 0;
        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            if(!valid(nr,nc,n,m)) {
                count++;
                continue;
            }
            if(grid[nr][nc] != 1) {
                count++;
                continue;
            }
            if(vis[nr][nc]) continue;
            count += dfs(nr, nc, grid, vis);
        }
        
        return count;
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) return dfs(i, j, grid, vis);
            }
        }
        
        return ans;
    }
};