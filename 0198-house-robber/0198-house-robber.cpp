class Solution {
public:
    int rob(vector<int>& nums) {
        // vector<int>dp(nums.size(),0);
        int prev1=nums[0];
        int prev2=nums[0];
        int ans;
        for(int i=1;i<nums.size();i++){
            if(i>1){
                ans=max(nums[i]+prev1,prev2);
            }
            else{
                ans=max(nums[i],prev2);
            }
            prev1=prev2;
            prev2=ans;
        }
        return prev2;
    }
};