class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        // This array stores prefix sum values of the previous row
        vector<int> colPrefix(n, 0);
        
        int count = 0;
        
        for (int i = 0; i < m; i++) {
            
            int left = 0;        // dp[i][j-1]
            int topLeft = 0;     // dp[i-1][j-1]
            
            for (int j = 0; j < n; j++) {
                
                int top = colPrefix[j];   // dp[i-1][j]
                
                // current 2D prefix sum
                int curr = grid[i][j] + top + left - topLeft;
                
                if (curr <= k) count++;
                
                // update variables for next iteration
                topLeft = top;
                colPrefix[j] = curr;
                left = curr;
            }
        }
        
        return count;
    }
};