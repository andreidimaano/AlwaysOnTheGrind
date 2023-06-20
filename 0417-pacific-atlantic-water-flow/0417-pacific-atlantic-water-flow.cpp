class Solution {
public:
    bool valid(int r, int c, int n, int m) {
        return (0 <= r && r < n && 0 <= c && c < m);
    }
    void dfs(int r, int c, vector<vector<int>>& heights, vector<vector<bool>> &vis) {
        vis[r][c] = true;
        int n = heights.size();
        int m = heights[0].size();

        vector<int> dr = {-1,1,0,0};
        vector<int> dc = {0,0,-1,1};

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
 
            if(!valid(nr,nc,n,m)) continue;
            if(vis[nr][nc]) continue;
            if(heights[nr][nc] < heights[r][c]) continue;
            dfs(nr, nc, heights, vis);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> result;

        vector<vector<bool>> pacVis(n, vector<bool>(m, false));
        vector<vector<bool>> atlVis(n, vector<bool>(m, false));
       
        for(int r = 0; r < n; r++) {
            int pacColumn = 0;
            int atlColumn = m - 1;
            dfs(r, pacColumn, heights, pacVis);
            dfs(r, atlColumn, heights, atlVis);
        }

        for(int c = 0; c < m; c++) {
            int pacRow = 0;
            int atlRow = n - 1;
            dfs(pacRow, c, heights, pacVis);
            dfs(atlRow, c, heights, atlVis);
        }

        for(int r = 0; r < n; r++) {
            for(int c = 0; c < m; c++) {
                if(pacVis[r][c] && atlVis[r][c]) result.push_back({r,c});
            }
        }

        return result;
    }
};