#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct SegTree {
        int n;
        vector<int> mn, mx, lazy;

        SegTree(int n_) : n(n_) {
            int sz = 4 * (n + 1);
            mn.assign(sz, 0);
            mx.assign(sz, 0);
            lazy.assign(sz, 0);
        }

        void apply(int u, int delta) {
            mn[u] += delta;
            mx[u] += delta;
            lazy[u] += delta;
        }

        void push(int u) {
            if (lazy[u] != 0) {
                int d = lazy[u];
                apply(u * 2, d);
                apply(u * 2 + 1, d);
                lazy[u] = 0;
            }
        }

        void addRange(int ql, int qr, int delta) { addRange(1, 0, n, ql, qr, delta); }

        void addRange(int u, int l, int r, int ql, int qr, int delta) {
            if (qr < l || r < ql) return;
            if (ql <= l && r <= qr) {
                apply(u, delta);
                return;
            }
            push(u);
            int m = (l + r) / 2;
            addRange(u * 2, l, m, ql, qr, delta);
            addRange(u * 2 + 1, m + 1, r, ql, qr, delta);
            mn[u] = min(mn[u * 2], mn[u * 2 + 1]);
            mx[u] = max(mx[u * 2], mx[u * 2 + 1]);
        }

        // Find the earliest index j such that A[j] == target.
        // We rely on the fact that target always exists (A[n] == now).
        int findFirstEqual(int target) { return findFirstEqual(1, 0, n, target); }

        int findFirstEqual(int u, int l, int r, int target) {
            if (l == r) return l;
            push(u);
            int left = u * 2, right = u * 2 + 1;
            int m = (l + r) / 2;

            // If target lies within [min,max] of left child, it must exist there.
            if (mn[left] <= target && target <= mx[left]) {
                return findFirstEqual(left, l, m, target);
            }
            return findFirstEqual(right, m + 1, r, target);
        }
    };

public:
    int longestBalanced(vector<int>& nums) {
        int n = (int)nums.size();
        SegTree st(n);

        // nums[i] <= 1e5, so vector is faster than unordered_map
        const int MAXV = 100000;
        vector<int> last(MAXV + 1, 0); // last occurrence position (1-based), 0 means unseen

        int now = 0;   // sum of votes over DISTINCT values seen so far
        int ans = 0;

        // We use positions 1..n for occurrences, and query A[j] over j in 0..n (cut position).
        for (int i = 1; i <= n; i++) {
            int x = nums[i - 1];
            int vote = (x % 2 == 0) ? 1 : -1;

            if (last[x] == 0) {
                // first time this value appears => new distinct value
                now += vote;
            } else {
                // value's last occurrence moves: remove its old suffix contribution
                st.addRange(last[x], n, -vote);
            }

            last[x] = i;

            // add new suffix contribution at i
            st.addRange(i, n, vote);

            // find smallest j with A[j] == now, so (j+1..i) balanced
            int j = st.findFirstEqual(now);
            ans = max(ans, i - j);
        }

        return ans;
    }
};
