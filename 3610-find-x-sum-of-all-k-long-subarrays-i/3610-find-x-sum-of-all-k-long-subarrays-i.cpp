class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;

        for (int i = 0; i + k <= nums.size(); i++) {
            vector<int> temp(nums.begin() + i, nums.begin() + i + k);
            unordered_map<int, int> freq;
            for (int val : temp) freq[val]++;

            vector<pair<int, int>> t(freq.begin(), freq.end());
            sort(t.begin(), t.end(), [](const pair<int,int>& a, const pair<int,int>& b){
                if (a.second != b.second) return a.second > b.second;
                return a.first > b.first;
            });

            int sum = 0;
            for (int j = 0; j < min(x, (int)t.size()); j++)
                sum += t[j].first * t[j].second;

            ans.push_back(sum);
        }

        return ans;
    }
};
