class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count=0;
        for(int num:nums){
            if(num==0)count++;
        }
        int id=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)continue;
            nums[id++]=nums[i];
        }
        while(id<nums.size())
        nums[id++]=0;
    }
};