class Solution {
public:
    int countUnguarded(int m, int n,
                       vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {

        // Using unordered sets for O(1) lookups
        unordered_set<long long> wallSet, guardSet;
        auto encode = [&](int r, int c) -> long long {
            return ((long long)r << 32) | c;
        };

        for (auto& w : walls)
            wallSet.insert(encode(w[0], w[1]));
        for (auto& g : guards)
            guardSet.insert(encode(g[0], g[1]));

        // Store guarded cells
        unordered_set<long long> seen;

        // Sweep per row using maps to stop early at walls
        unordered_map<int, vector<int>> guardRows, wallRows;
        for (auto& g : guards) guardRows[g[0]].push_back(g[1]);
        for (auto& w : walls) wallRows[w[0]].push_back(w[1]);
        for (auto& [r, vec] : guardRows) sort(vec.begin(), vec.end());
        for (auto& [r, vec] : wallRows) sort(vec.begin(), vec.end());

        // Horizontal sweeps (row-wise)
        for (auto& [r, gcols] : guardRows) {
            for (int gc : gcols) {
                // Right
                for (int c = gc + 1; c < n; ++c) {
                    long long key = encode(r, c);
                    if (wallSet.count(key) || guardSet.count(key)) break;
                    seen.insert(key);
                }
                // Left
                for (int c = gc - 1; c >= 0; --c) {
                    long long key = encode(r, c);
                    if (wallSet.count(key) || guardSet.count(key)) break;
                    seen.insert(key);
                }
            }
        }

        // Vertical sweeps (column-wise)
        unordered_map<int, vector<int>> guardCols, wallCols;
        for (auto& g : guards) guardCols[g[1]].push_back(g[0]);
        for (auto& w : walls) wallCols[w[1]].push_back(w[0]);
        for (auto& [c, vec] : guardCols) sort(vec.begin(), vec.end());
        for (auto& [c, vec] : wallCols) sort(vec.begin(), vec.end());

        for (auto& [c, grows] : guardCols) {
            for (int gr : grows) {
                // Down
                for (int r = gr + 1; r < m; ++r) {
                    long long key = encode(r, c);
                    if (wallSet.count(key) || guardSet.count(key)) break;
                    seen.insert(key);
                }
                // Up
                for (int r = gr - 1; r >= 0; --r) {
                    long long key = encode(r, c);
                    if (wallSet.count(key) || guardSet.count(key)) break;
                    seen.insert(key);
                }
            }
        }

        // Total unguarded = total cells - walls - guards - seen
        long long total = (long long)m * n;
        long long blocked = walls.size() + guards.size() + seen.size();
        return total - blocked;
    }
};
