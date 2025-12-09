class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1'000'000'007;
        int n = nums.size();

        unordered_map<int,int> leftCount, rightCount;

        for (int x : nums)
            rightCount[x]++;

        long long ans = 0;

        for (int j = 0; j < n; j++) {
            int x = nums[j];
            rightCount[x]--;  // remove j from right side

            int need = x * 2;

            long long left = leftCount[need];
            long long right = rightCount[need];

            ans = (ans + left * right) % MOD;

            leftCount[x]++;   // add j to left side
        }

        return ans;
    }
};
