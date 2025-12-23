class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        unordered_map<int,int>freq;
        int i=0;
        for(int num:nums){
            freq[num]=i++;
        }
        for(i=0;i<nums.size();i++){
            // cout<<target-nums[i]<<endl;
            if(freq.find(target-nums[i])!=freq.end()&&freq[target-nums[i]]!=i){
                ans.push_back(i);
                ans.push_back(freq[(target-nums[i])]);
                sort(ans.begin(),ans.end());
                return ans;
            }
        }
        return ans;
    }
};