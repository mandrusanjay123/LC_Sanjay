class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const long MOD = 1e9 + 7;
        int n = nums.size();
        
        // max value ≤ 100000, so max target = 200000
        vector<long> left(200001, 0), right(200001, 0);

        for (int x : nums) right[x]++;

        long ans = 0;

        for (int j = 0; j < n; j++) {
            int mid = nums[j];

            // remove j from right side
            right[mid]--;

            long target = (long)mid * 2;
            if (target <= 200000) {
                ans = (ans + left[target] * right[target]) % MOD;
            }

            // add j to left
            left[mid]++;
        }

        return ans;
    }
};
