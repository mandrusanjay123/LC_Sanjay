class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool>ans;
        int mod=1e9;
        int val=0;
        for(int i=0;i<nums.size();i++){
            if(val>=mod)val%=mod;
            val=val*2+nums[i];
            if(val%5==0){
                // val=0;
                ans.push_back(true);
            }
            else ans.push_back(false);
        }
        return ans;
    }
};