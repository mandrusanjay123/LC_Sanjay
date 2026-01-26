class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int min_diff=INT_MAX;
        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1]<min_diff)min_diff=nums[i]-nums[i-1];
        }
        vector<vector<int>>ans;
        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1]==min_diff){
                vector<int>temp;
                temp.push_back(nums[i-1]);
                temp.push_back(nums[i]);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};