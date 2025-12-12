class Solution {
public:
    bool checkIfPossible(int target,vector<int>& nums){
        vector<int>dp(target+1,0);
        dp[0]=1;
        for(int i=0;i<nums.size();i++){
            for(int j=target;j>=nums[i];j--){
                dp[j]=dp[j-nums[i]]||dp[j];
                if(dp[target])return true;
            }
        }
        return false;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2!=0)return false;
        sum/=2;
        if(checkIfPossible(sum,nums))return true;
        return false;
    }
};