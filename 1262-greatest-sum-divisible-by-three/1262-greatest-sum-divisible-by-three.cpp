class Solution {
public:
    vector<vector<int>> dp;
    vector<int> nums;
    int n;

    int solve(int i, int rem) {
        if (i == n)
            return rem == 0 ? 0 : INT_MIN / 2;

        if (dp[i][rem] != INT_MIN)
            return dp[i][rem];

        int notTake = solve(i + 1, rem);

        int newRem = (rem + nums[i]) % 3;
        int take = nums[i] + solve(i + 1, newRem);

        return dp[i][rem] = max(take, notTake);
    }

    int maxSumDivThree(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        dp.assign(n, vector<int>(3, INT_MIN));
        return solve(0, 0);
    }
};