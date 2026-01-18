class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Row prefix
        vector<vector<int>> prefixRow(m, vector<int>(n, 0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(j==0) prefixRow[i][j] = grid[i][j];
                else prefixRow[i][j] = prefixRow[i][j-1] + grid[i][j];
            }
        }

        // Col prefix
        vector<vector<int>> prefixCol(m, vector<int>(n, 0));
        for(int j=0;j<n;j++){
            for(int i=0;i<m;i++){
                if(i==0) prefixCol[i][j] = grid[i][j];
                else prefixCol[i][j] = prefixCol[i-1][j] + grid[i][j];
            }
        }

        // Diagonal prefixes
        vector<vector<int>> diag1(m, vector<int>(n,0)); // 
        vector<vector<int>> diag2(m, vector<int>(n,0)); // /
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                diag1[i][j] = grid[i][j] + (i>0 && j>0 ? diag1[i-1][j-1] : 0);
                diag2[i][j] = grid[i][j] + (i>0 && j+1<n ? diag2[i-1][j+1] : 0);
            }
        }

        auto rowSum = [&](int r,int c1,int c2){
            return prefixRow[r][c2] - (c1>0 ? prefixRow[r][c1-1] : 0);
        };
        auto colSum = [&](int c,int r1,int r2){
            return prefixCol[r2][c] - (r1>0 ? prefixCol[r1-1][c] : 0);
        };
        auto diag1Sum = [&](int r1,int c1,int r2,int c2){
            return diag1[r2][c2] - (r1>0 && c1>0 ? diag1[r1-1][c1-1] : 0);
        };
        auto diag2Sum = [&](int r1,int c1,int r2,int c2){
            return diag2[r2][c1] - (r1>0 && c2+1<n ? diag2[r1-1][c2+1] : 0);
        };

        for(int k=min(m,n); k>=1; k--){
            for(int i=0;i+k-1<m;i++){
                for(int j=0;j+k-1<n;j++){
                    int r2=i+k-1, c2=j+k-1;
                    int target = rowSum(i,j,c2);
                    bool ok=true;

                    // rows
                    for(int r=i;r<=r2;r++){
                        if(rowSum(r,j,c2)!=target){ ok=false; break; }
                    }

                    // cols
                    for(int c=j;c<=c2 && ok;c++){
                        if(colSum(c,i,r2)!=target){ ok=false; break; }
                    }

                    // diagonals
                    if(ok && diag1Sum(i,j,r2,c2)!=target) ok=false;
                    if(ok && diag2Sum(i,j,r2,c2)!=target) ok=false;

                    if(ok) return k;
                }
            }
        }
        return 1;
    }
};
