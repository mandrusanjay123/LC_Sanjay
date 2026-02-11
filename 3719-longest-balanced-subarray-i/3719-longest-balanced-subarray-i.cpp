class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = (int)nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_set<int> seen; // numbers already present in nums[i..j]
            int evenDistinct = 0, oddDistinct = 0;

            for (int j = i; j < n; j++) {
                if (seen.insert(nums[j]).second) { // first time nums[j] appears in this subarray
                    if ((nums[j] & 1) == 0) evenDistinct++;
                    else oddDistinct++;
                }

                if (evenDistinct == oddDistinct) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};
