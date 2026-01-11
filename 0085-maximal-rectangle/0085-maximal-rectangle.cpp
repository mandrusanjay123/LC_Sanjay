class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;

        vector<vector<int>> maxDepth(matrix.size(),
                                     vector<int>(matrix[0].size(), 0));

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(i==0){
                    maxDepth[i][j]=matrix[i][j]-'0';
                }
                else if(matrix[i][j]=='1'){
                    maxDepth[i][j]=maxDepth[i-1][j]+1;
                } else {
                    maxDepth[i][j]=0;
                }
            }
        }

        int max_area=0;

        for(int i=0;i<maxDepth.size();i++){
            for(int j=0;j<maxDepth[i].size();j++){
                int minH = maxDepth[i][j];
                for(int k=j; k<maxDepth[i].size() && minH>0; k++){
                    minH = min(minH, maxDepth[i][k]);
                    int width = k - j + 1;
                    max_area = max(max_area, minH * width);
                }
            }
        }
        return max_area;
    }
};
