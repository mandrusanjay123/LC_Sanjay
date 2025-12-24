class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int>ans;
        ans.resize(nums.size());
        int i=0;
        int j=nums.size()-1;
        for(int id=0;id<nums.size();id++){
            if(nums[id]%2==0){
                ans[i++]=nums[id];
            }
            else{
                ans[j--]=nums[id];
            }
        }
        return ans;
    }
};