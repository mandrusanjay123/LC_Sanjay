class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int freq=0;
        int num=-1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                freq++;
                num=nums[i];
            }
        }
        return num;
    }
};