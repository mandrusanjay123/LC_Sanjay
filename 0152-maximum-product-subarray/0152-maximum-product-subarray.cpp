class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curr_max=nums[0];
        int curr_min=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0){
                swap(curr_max,curr_min);
            }
            curr_max=max(nums[i],curr_max*nums[i]);
            curr_min=min(nums[i],curr_min*nums[i]);
            ans=max(ans,curr_max);
            
        }
        return ans;
    }
};