class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l=0;
        int r=nums.size()-1;
        vector<int>sums;
        while(l<r){
            sums.push_back(nums[l++]+nums[r--]);
        }
        int ans=0;
        for(int s:sums){
            ans=max(ans,s);
        }
        return ans;
    }
};