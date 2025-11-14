class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>ans(n,(vector<int>(n,0)));
        for(int i=0;i<queries.size();i++){
            // for(int j=0;j<queries[i].size();j++){
                for(int r=queries[i][0];r<=queries[i][2];r++){
                    for(int c=queries[i][1];c<=queries[i][3];c++){
                        // cout<<r<<' '<<c<<endl;
                        ans[r][c]+=1;
                    }
                }
            // }
        }
        return ans;
    }
};