class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),0);
        dp[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            if(i>1){
                dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
            }
            else{
                dp[i]=max(nums[i],dp[i-1]);
            }
        }
        return dp[nums.size()-1];
    }
};