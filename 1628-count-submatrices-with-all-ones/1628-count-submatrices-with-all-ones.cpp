class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        vector<vector<int>>hist(mat.size(),(vector<int>(mat[0].size(),0)));
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
               if(mat[i][j]==1&&i!=0){
                hist[i][j]=mat[i][j]+hist[i-1][j];
               }
               else
               hist[i][j]=mat[i][j];
            }
        }
        int ans=0;
         for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                // cout<<hist[i][j]<<",";
                int minH=INT_MAX;
                for(int k=j;k>=0;k--){
                    if(hist[i][k]==0)break;
                    minH=min(minH,hist[i][k]);
                    ans+=minH;
                }

            }
            // cout<<endl;
            }
            return ans;
    }
};