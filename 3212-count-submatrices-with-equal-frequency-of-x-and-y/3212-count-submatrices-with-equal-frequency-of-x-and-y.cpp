class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int count =0;
        vector<vector<pair<int,int>>>freq(grid.size(),vector<pair<int,int>>(grid[0].size(),{0,0}));
        for(int i=0;i<grid.size();i++){
            // int freqX=0;
            // int freqY=0;
            for(int j=0;j<grid[i].size();j++){
                freq[i][j].first+=(grid[i][j]=='X')?1:0;
                freq[i][j].second+=(grid[i][j]=='Y')?1:0;
                if(i-1>=0){
                    freq[i][j].first+=freq[i-1][j].first;
                    freq[i][j].second+=freq[i-1][j].second;
                }
                if(j-1>=0){
                    freq[i][j].first+=freq[i][j-1].first;
                    freq[i][j].second+=freq[i][j-1].second;
                }
                if(i-1>=0&&j-1>=0){
                    freq[i][j].first-=freq[i-1][j-1].first;
                    freq[i][j].second-=freq[i-1][j-1].second;
                }
                if(freq[i][j].first==freq[i][j].second&&freq[i][j].first!=0){
                    count++;
                }
                
            }
        }
        return count;
    }
};