#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        // set automatically keeps values sorted (ascending)
        // we will later take from reverse
        set<int> st;

        // try every possible TOP corner of rhombus
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {

                // size 0 rhombus (single cell)
                st.insert(grid[r][c]);

                // maximum possible size for rhombus with top at (r,c)
                int maxSize = min({ (m - 1 - r) / 2, c, n - 1 - c });

                // try all sizes
                for (int k = 1; k <= maxSize; k++) {

                    int sum = 0;

                    // ---- edge 1: top → right (down-right diagonal) ----
                    for (int i = 0; i < k; i++) {
                        sum += grid[r + i][c + i];
                    }

                    // ---- edge 2: right → bottom (down-left diagonal) ----
                    for (int i = 0; i < k; i++) {
                        sum += grid[r + k + i][c + k - i];
                    }

                    // ---- edge 3: bottom → left (up-left diagonal) ----
                    for (int i = 0; i < k; i++) {
                        sum += grid[r + 2 * k - i][c - i];
                    }

                    // ---- edge 4: left → top (up-right diagonal) ----
                    for (int i = 0; i < k; i++) {
                        sum += grid[r + k - i][c - k + i];
                    }

                    st.insert(sum);
                }
            }
        }

        // collect top 3 distinct values
        vector<int> ans;
        for (auto it = st.rbegin(); it != st.rend() && ans.size() < 3; it++) {
            ans.push_back(*it);
        }

        return ans;
    }
};