class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),0));
        int count=0;
        for(int i = 0;i < grid.size(); i++){

            for(int j = 0; j<grid[i].size(); j++){
                int previ = i-1;
                int prevj = j-1;
                dp[i][j]+=grid[i][j];
                
                if(previ>=0){
                    dp[i][j]+=dp[previ][j];
                }
                if(prevj>=0){
                    dp[i][j]+=dp[i][prevj];
                }
                if(previ >= 0 && prevj >= 0){
                    dp[i][j] -= dp[previ][prevj];
                }
                 if(dp[i][j]<=k) count++;
                // cout<<dp[i][j]<<","; 
            }
            // cout<<endl;

        }

        // int count=0;
        //     for(int i = 0; i<grid.size(); i++){
        //         for(int j=0 ;j<grid[i].size(); j++){
                    
        //             if(dp[i][j]<=k) count++;
        //         }
                
        //     }

        return count;
    }
};