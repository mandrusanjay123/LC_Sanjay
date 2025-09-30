class Solution {
public:
    int triangularSum(vector<int>& nums) {
        vector<int>newNums;
        newNums.push_back(0);
        newNums.push_back(0);
        int sum=0;
        if(nums.size()==1)return nums[0];
        while(newNums.size()>1){
            newNums.clear();
            for(int i=1;i<nums.size();i++){
                newNums.push_back((nums[i]+nums[i-1])%10);
            }
            if(newNums.size()==1)sum=newNums[0];
            nums=newNums;
        }
        return sum;
    }
};