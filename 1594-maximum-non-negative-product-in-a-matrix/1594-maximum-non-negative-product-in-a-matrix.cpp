class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        long long MOD = 1e9 + 7;
        
        vector<vector<long long>> maxDP(m, vector<long long>(n));
        vector<vector<long long>> minDP(m, vector<long long>(n));
        
        maxDP[0][0] = grid[0][0];
        minDP[0][0] = grid[0][0];
        
        // first row
        for(int j = 1; j < n; j++){
            long long x = grid[0][j];
            maxDP[0][j] = maxDP[0][j-1] * x;
            minDP[0][j] = maxDP[0][j];
        }
        
        // first column
        for(int i = 1; i < m; i++){
            long long x = grid[i][0];
            maxDP[i][0] = maxDP[i-1][0] * x;
            minDP[i][0] = maxDP[i][0];
        }
        
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                
                long long x = grid[i][j];
                
                long long a = maxDP[i-1][j] * x;
                long long b = minDP[i-1][j] * x;
                long long c = maxDP[i][j-1] * x;
                long long d = minDP[i][j-1] * x;
                
                maxDP[i][j] = max({a,b,c,d});
                minDP[i][j] = min({a,b,c,d});
            }
        }
        
        long long ans = maxDP[m-1][n-1];
        
        if(ans < 0) return -1;
        return ans % MOD;
    }
};