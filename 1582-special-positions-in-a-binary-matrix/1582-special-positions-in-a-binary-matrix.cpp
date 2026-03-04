class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        vector<int>cols(mat[0].size(),0);
        vector<int>rows(mat.size(),0);
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==1)
                {
                    rows[i]+=1;
                    cols[j]+=1;
                }
            }
        }

        int count=0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==1){
                    if(cols[j]<=1&&rows[i]<=1)count++;
                }
            }
        }

        return count;
    }
};