class Solution {
public:
    void findPermutation(vector<int>& nums,vector<int>&temp,vector<vector<int>>&ans,vector<bool>&visited){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!visited[i]){
            visited[i]=true;
            temp.push_back(nums[i]);
            findPermutation(nums,temp,ans,visited);
            temp.pop_back();
            visited[i]=false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        vector<bool>visited(nums.size(),false);
        findPermutation(nums,temp,ans,visited);
        return ans;
    }
};