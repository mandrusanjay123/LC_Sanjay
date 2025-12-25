class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long res = 0;
        nth_element(happiness.begin(), happiness.begin() + k, happiness.end(), greater<int>());
        sort(happiness.begin(), happiness.begin() + k, greater<int>());
        for(int i = 0; i < k; ++i){
            int val = happiness[i] - i;
            if(val <= 0) break;
            res += val;
        }
        return res;
    }
};