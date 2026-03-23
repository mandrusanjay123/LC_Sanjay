class Solution {
public:
    
    int m, n;
    long long MOD = 1e9 + 7;
    
    // memo stores {maxProduct, minProduct}
    vector<vector<pair<long long,long long>>> memo;
    vector<vector<int>> vis;
    
    pair<long long,long long> dfs(vector<vector<int>>& grid, int i, int j) {
        
        if(vis[i][j]) return memo[i][j];
        
        long long val = grid[i][j];
        
        // base
        if(i == 0 && j == 0) {
            return memo[i][j] = {val, val};
        }
        
        long long mx = LLONG_MIN;
        long long mn = LLONG_MAX;
        
        // from up
        if(i > 0) {
            auto p = dfs(grid, i-1, j);
            
            mx = max(mx, max(p.first * val, p.second * val));
            mn = min(mn, min(p.first * val, p.second * val));
        }
        
        // from left
        if(j > 0) {
            auto p = dfs(grid, i, j-1);
            
            mx = max(mx, max(p.first * val, p.second * val));
            mn = min(mn, min(p.first * val, p.second * val));
        }
        
        vis[i][j] = 1;
        return memo[i][j] = {mx, mn};
    }
    
    int maxProductPath(vector<vector<int>>& grid) {
        
        m = grid.size();
        n = grid[0].size();
        
        memo.assign(m, vector<pair<long long,long long>>(n));
        vis.assign(m, vector<int>(n, 0));
        
        auto res = dfs(grid, m-1, n-1);
        
        long long ans = res.first;
        
        if(ans < 0) return -1;
        
        return ans % MOD;
    }
};