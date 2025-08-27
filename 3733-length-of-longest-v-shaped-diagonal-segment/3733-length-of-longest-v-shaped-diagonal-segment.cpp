class Solution {
public:
    // 0: ↘, 1: ↙, 2: ↖, 3: ↗
    int DIRS[4][2] = {{1,1},{1,-1},{-1,-1},{-1,1}};
    
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int m = (int)grid.size(), n = (int)grid[0].size();
        // state = (dir << 1) | canTurn   -> 8 states per cell
        vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, vector<int>(8, -1)));
        int ans = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 1) continue;
                for (int k = 0; k < 4; ++k) {
                    ans = max(ans, 1 + dfs(i, j, k, 1, 2, grid, memo)); // start at 1, next target is 2
                }
            }
        }
        return ans;
    }

    int dfs(int i, int j, int k, int canTurn, int target,
            vector<vector<int>>& grid,
            vector<vector<vector<int>>>& memo) {
        int ni = i + DIRS[k][0];
        int nj = j + DIRS[k][1];
        int m = (int)grid.size(), n = (int)grid[0].size();

        if (ni < 0 || nj < 0 || ni >= m || nj >= n || grid[ni][nj] != target) return 0;

        int mask = (k << 1) | canTurn;
        int &dp = memo[ni][nj][mask];
        if (dp != -1) return dp;

        // continue straight (alternate 2 <-> 0)
        int best = dfs(ni, nj, k, canTurn, 2 - target, grid, memo);

        if (canTurn) {
            int nk = (k + 1) & 3;                 // clockwise 90°
            best = max(best, dfs(ni, nj, nk, 0, 2 - target, grid, memo));
        }
        return dp = best + 1;
    }
};
