class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        const int INF = 1e9;

        // dp[t][v] = min cost to reach v using exactly t time
        vector<vector<int>> dp(maxTime + 1, vector<int>(n, INF));
        dp[0][0] = passingFees[0];

        for (int t = 0; t <= maxTime; t++) {
            for (auto &e : edges) {
                int u = e[0], v = e[1], w = e[2];

                if (t + w <= maxTime) {
                    // u -> v
                    if (dp[t][u] != INF) {
                        dp[t + w][v] = min(dp[t + w][v], dp[t][u] + passingFees[v]);
                    }
                    // v -> u (because undirected)
                    if (dp[t][v] != INF) {
                        dp[t + w][u] = min(dp[t + w][u], dp[t][v] + passingFees[u]);
                    }
                }
            }
        }

        int ans = INF;
        for (int t = 0; t <= maxTime; t++) {
            ans = min(ans, dp[t][n - 1]);
        }
        return (ans == INF) ? -1 : ans;
    }
};
