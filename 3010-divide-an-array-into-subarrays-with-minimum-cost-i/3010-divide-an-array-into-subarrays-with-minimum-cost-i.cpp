class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int ans=nums[0];
        int min1=INT_MAX;
        int min2=INT_MAX;
        int id=-1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<min1){
                min1=nums[i];
                id=i;
                
            }
        }
        for(int i=1;i<nums.size();i++){
            if(nums[i]<min2&&i!=id){
                min2=nums[i];
            }
        }
        // cout<<min1<<","<<min2;
        return ans+min1+min2;
    }
};