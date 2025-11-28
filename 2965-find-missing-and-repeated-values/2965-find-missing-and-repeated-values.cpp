class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        int len=n*n;
        vector<int>count(len+1,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                count[grid[i][j]]++;
            }
        }
        vector<int>ans;
        int missing;
        for(int i=1;i<=len;i++){
            if(count[i]==2)ans.push_back(i);
            if(count[i]==0)missing=i;
        }
        ans.push_back(missing);
        return ans;
    }
};