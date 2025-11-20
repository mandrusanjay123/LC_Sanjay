class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {

        // FIX #1 + FIX #2: required comparator
        sort(intervals.begin(), intervals.end(),
            [](auto &a, auto &b){
                if (a[1] == b[1]) return a[0] > b[0];
                return a[1] < b[1];
            });

        vector<int> chosen;

        for (auto &in : intervals) {
            int L = in[0], R = in[1];
            int hits = 0;

            // count already chosen
            for (int x : chosen)
                if (x >= L && x <= R) hits++;

            // need 2
            if (hits == 0) {
                chosen.push_back(R - 1);
                chosen.push_back(R);
            }
            // need 1 more
            else if (hits == 1) {
                chosen.push_back(R);
            }
        }

        return chosen.size();
    }
};
