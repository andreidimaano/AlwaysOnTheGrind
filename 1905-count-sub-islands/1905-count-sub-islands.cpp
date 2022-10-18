class Solution {
public:
    bool valid(int r, int c, int n , int m) {
        return (0 <= r && r < n && 0 <= c && c < m);
    }
    void dfs(int r, int c, int island,vector<vector<int>>& grid, vector<vector<bool>>& vis) {
        vis[r][c] = true;
        grid[r][c] = island;
        int n = grid.size();
        int m = grid[0].size();
        
        vector<int> dr = {-1,1,0,0};
        vector<int> dc = {0,0,-1,1};
        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            if(!valid(nr, nc, n, m)) continue;
            if(vis[nr][nc]) continue;
            if(grid[nr][nc] != 1) continue;
            
            dfs(nr, nc, island, grid, vis);
        }
        
    }
    bool checkSubIsland(int r, int c, int island, vector<vector<int>>& grid2, vector<vector<int>>& grid1, vector<vector<bool>>& vis) {
        bool ans = true;
        vis[r][c] = true;
        if(grid1[r][c] == 0 || grid1[r][c] != island) {
            ans = false;
        }
        
        int n = grid1.size();
        int m = grid1[0].size();
        vector<int> dr = {-1,1,0,0};
        vector<int> dc = {0,0,-1,1};
        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            if(!valid(nr, nc, n, m)) continue;
            if(vis[nr][nc]) continue;
            if(grid2[nr][nc] != 1) continue;
            
            if(!checkSubIsland(nr, nc, island, grid2, grid1, vis)) {
                ans = false;
            }
        }
        
        
        return ans;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        
        vector<vector<bool>> vis1(n, vector<bool>(m, false));
        int island = -1;
        for(int r = 0; r < n; r++) {
            for(int c = 0; c < m; c++) {
                if(!vis1[r][c] && grid1[r][c] == 1) {
                    dfs(r, c, island, grid1, vis1);
                    island--;
                }
            }
        }
        
        int ans = 0;
        vector<vector<bool>> vis2(n, vector<bool>(m, false));
        for(int r = 0; r < n; r++) {
            for(int c = 0; c < m; c++) {
                if(!vis2[r][c] && grid2[r][c] == 1) {
                    int island = grid1[r][c];
                    ans = checkSubIsland(r, c, island, grid2, grid1, vis2) ? ans + 1: ans;
                }
            }
        }
        
        return ans;
        
    }
};