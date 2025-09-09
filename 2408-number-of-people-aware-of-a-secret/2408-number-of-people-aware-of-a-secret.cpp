#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1'000'000'007;

        // add[d] = # of people who first learn the secret on day d
        vector<long long> add(n + 1, 0);
        add[1] = 1;                // day 1: one person learns
        long long shareable = 0;   // # of people who can share today
        long long aware = 1;       // # of people who still remember today

        for (int day = 2; day <= n; ++day) {
            // People who learned on (day - delay) become eligible to share today
            if (day - delay >= 1) {
                shareable += add[day - delay];
                if (shareable >= MOD) shareable -= MOD;
            }
            // People who learned on (day - forget) forget today and can no longer share
            if (day - forget >= 1) {
                shareable -= add[day - forget];
                if (shareable < 0) shareable += MOD;
            }

            // Those eligible to share each tell exactly one new person today
            add[day] = shareable;                 // new learners today
            aware += add[day];                    // they now remember
            if (aware >= MOD) aware -= MOD;

            // People who learned on (day - forget) forget today; remove from 'aware'
            if (day - forget >= 1) {
                aware -= add[day - forget];
                if (aware < 0) aware += MOD;
            }
        }
        return (int)(aware % MOD);
    }
};
