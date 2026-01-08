class Solution {
public:
    void recursion(int id,int sum, vector<int>& candidates,vector<int>&temp,vector<vector<int>>&ans){
        if(sum==0){
            ans.push_back(temp);
            return;
        }
        for(int i=id;i<candidates.size();i++){
            if(i>id&&candidates[i]==candidates[i-1])continue;
            if(candidates[i]>sum)break;
            temp.push_back(candidates[i]);
            recursion(i+1,sum-candidates[i],candidates,temp,ans);
            temp.pop_back();
            // recursion(i+1,sum,candidates,temp,ans);
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>temp;
        vector<vector<int>>ans;
        sort(candidates.begin(),candidates.end());
        recursion(0,target,candidates,temp,ans);
        return ans;
    }
};