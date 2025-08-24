class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0, zeros = 0, ans = 0;

        for (int right = 0; right < n; ++right) {
            if (nums[right] == 0) ++zeros;

            // shrink until the window has at most one zero
            while (zeros > 1) {
                if (nums[left] == 0) --zeros;
                ++left;
            }

            // window [left..right] has 0 or 1 zero
            // after deleting one element, effective 1's length = (right - left)
            ans = max(ans, right - left);
        }
        return ans;
    }
};
