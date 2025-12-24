class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_len=0;
        if(nums.size()==1){
            if(nums[0]==1)return 1;
            else return 0;
        }
        int curr_len=1;
        bool atleast_1_1=false;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==1||nums[i-1]==1)atleast_1_1=true;
            if(nums[i]==1&&nums[i]==nums[i-1]){
                curr_len++;
            }
            else{
                curr_len=1;
            }
            max_len=max(max_len,curr_len);
        }
        if(!atleast_1_1)return 0;
        return max_len;
    }
};