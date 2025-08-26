class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int max_area=-1;
        int max_dig=-1;
        for(int i=0;i<dimensions.size();i++){
            int dig=(dimensions[i][0]*dimensions[i][0])+(dimensions[i][1]*dimensions[i][1]);
            int area=dimensions[i][0]*dimensions[i][1];
            if(max_dig<dig){
                max_dig=dig;
                max_area=area;
            }
            else if(dig==max_dig&&area>max_area){
                max_area=area;
            }
        }
        return max_area;
    }
};