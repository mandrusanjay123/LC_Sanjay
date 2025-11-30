class Solution {
public:
    long long hoursNeeded(const vector<int>& piles, long long k) {
        long long h = 0;
        for (long long num : piles) {
            h += (num + k - 1) / k;   // ceil(num/k)
        }
        return h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        long long low = 1;
        long long high = *max_element(piles.begin(), piles.end());
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (hoursNeeded(piles, mid) <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return (int)ans;
    }
};
