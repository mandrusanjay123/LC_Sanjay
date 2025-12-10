class Solution {
public:
    const int MOD = 1000000000+7;
    int countPermutations(vector<int>& nums) {
        int key=nums[0];
        sort(nums.begin(),nums.end());
        int i;
        for(i=0;i<nums.size();i++){
            if(key==nums[i])break;
        }
        if(i!=0)return 0;
        if(i+1<nums.size()&&nums[i+1]==key)return 0;

        int combinations=nums.size()-1-i;
        long long ans=1;
        for(int i=1;i<=combinations;i++){
            ans=(ans*i)%MOD;
        }
        return ans;
    }
};