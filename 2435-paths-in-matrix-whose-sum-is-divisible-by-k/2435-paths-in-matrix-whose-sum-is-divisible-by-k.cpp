class Solution {
public:
    int m, n, K;
    const int MOD = 1000000007;
    vector<vector<vector<int>>> dp;

    bool isValid(int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    int solve(int i, int j, int sum, vector<vector<int>>& grid) {
        if (!isValid(i, j)) return 0;

        sum = (sum + grid[i][j]) % K;

        if (i == m - 1 && j == n - 1)
            return (sum % K == 0) ? 1 : 0;

        if (dp[i][j][sum] != -1)
            return dp[i][j][sum];

        long long down = solve(i + 1, j, sum, grid);
        long long right = solve(i, j + 1, sum, grid);

        return dp[i][j][sum] = (down + right) % MOD;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        K = k;

        dp.assign(m, vector<vector<int>>(n, vector<int>(k, -1)));

        return solve(0, 0, 0, grid);
    }
};