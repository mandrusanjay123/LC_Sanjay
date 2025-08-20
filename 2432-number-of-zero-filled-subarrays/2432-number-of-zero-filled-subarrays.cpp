class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = (int)nums.size();
        if (n == 0) return 0;

        std::vector<int> freq(n + 1, 0);

        // Find frequencies of zero-run lengths
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0 && (i == 0 || nums[i - 1] != 0)) {
                int cnt = 0;
                int j = i;
                while (j < n && nums[j] == 0) {
                    ++cnt;
                    ++j;
                }
                ++freq[cnt];
                i = j - 1; // for-loop will ++i next
            }
        }

        // Sum up number of subarrays from each zero-run length
        long long ans = 0;
        for (int len = 1; len <= n; ++len) {
            if (freq[len] > 0) {
                long long add = 1LL * len * (len + 1) / 2; // subarrays from one run
                ans += add * freq[len];
            }
        }
        return ans;
    }
};
