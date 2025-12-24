class Solution {
public:
int n,m;
bool isvalid(int i,int j){
    if(i<n&&i>=0&&j<m&&j>=0)return true;
    return false;
}
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        n=matrix.size();
        m=matrix[0].size();
        if(n==1||m==1)return true;
        //(2,0)
        //(1,0)(2,1)
        //(0,0)(1,1)(2,2)
        //(0,1)(1,2)(2,3)
        //(0,2)(1,3)
        int i=0;
        int j=0;
        for(i;i<n;i++){
            int ni=i+1;
            int nj=j+1;
            while(isvalid(ni,nj)){
                if(matrix[i][j]!=matrix[ni][nj])return false;
                ni+=1;
                nj+=1;
            }
        }
        i=0;
        j=0;
        for(j;j<m;j++){
            int ni=i+1;
            int nj=j+1;
            while(isvalid(ni,nj)){
                if(matrix[i][j]!=matrix[ni][nj])return false;
                ni+=1;
                nj+=1;
            }
        }
        return true;
    }
};