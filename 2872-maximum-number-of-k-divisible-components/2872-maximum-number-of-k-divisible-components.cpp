class Solution {
public:
    int components = 0;

    long long dfs(int u, int parent, vector<vector<int>>& adj, vector<int>& values, int k) {
        long long sum = values[u];

        for (int v : adj[u]) {
            if (v == parent) continue;
            sum += dfs(v, u, adj, values, k);
        }

        if (sum % k == 0) {
            components++;
            return 0;           // cut this component
        }

        return sum;             // pass sum upward
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(0, -1, adj, values, k);

        return components;
    }
};
