class Solution {
public:
    void dfs(int node, unordered_map<int, vector<pair<int, int>>>& m, int& count, vector<bool>& vis) {
        vis[node] = true;
        
        for(auto nei: m[node]) {
            if(vis[nei.first]) continue;
            if(nei.second == 1) count++;
            dfs(nei.first, m, count, vis);
        }
        
        return;
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<bool> vis(n, false);
        unordered_map<int, vector<pair<int, int>>> m;
        
        for(auto e: connections) {
            m[e[0]].push_back(make_pair(e[1], 1)); //out
            m[e[1]].push_back(make_pair(e[0], -1)); //in
        }
        
        int count = 0;
        dfs(0, m, count, vis);
        
        return count;
    }
};