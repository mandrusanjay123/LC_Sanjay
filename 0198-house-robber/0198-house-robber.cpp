class Solution {
public:
    int recursion(int i,vector<int>& nums,vector<int>& memo){
        if(i==0)return nums[0];
        if(i<0)return 0;
        if(memo[i]!=-1)return memo[i];
        int rob= recursion(i-2,nums,memo)+nums[i];
        int not_rob= recursion(i-1,nums,memo);
        return memo[i]= max(rob,not_rob);
    }
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(),-1);
        return recursion(nums.size()-1,nums,memo);
    }
};