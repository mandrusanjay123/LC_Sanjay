class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l=0;
        int r=nums.size()-1;
        // vector<int>sums;
        int ans=0;
        while(l<r){
            // sums.push_back(nums[l++]+nums[r--]);
            ans=max(ans,nums[l++]+nums[r--]);
        }
        
        // for(int s:sums){
        //     ans=max(ans,s);
        // }
        return ans;
    }
};