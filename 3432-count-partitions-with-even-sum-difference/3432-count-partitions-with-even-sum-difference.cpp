class Solution {
public:
    int countPartitions(vector<int>& nums) {
        vector<int>prefix(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            if(i>0)prefix[i]=prefix[i-1]+nums[i];
            else prefix[i]=nums[i];
        }
        // for(int p:prefix)cout<<p<<" "<<endl;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int left=prefix[i];
            int right=prefix[nums.size()-1]-prefix[i];
            // cout<<right<<" "<<left<<endl;
            if(i<nums.size()-1)if((left-right)%2==0)ans++;
        }
        return ans;
    }

};