class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum=0;
        int min_elem=INT_MAX;
        int neg_cnt=0;
        for(auto v:matrix){
            for(int x:v){
                min_elem=min(abs(x),min_elem);
                if(x<0){
                    neg_cnt++;
                    sum-=x;
                }
                else{
                    sum+=x;
                }
            }
        }
        return (neg_cnt%2==0)?sum:sum-2*min_elem;
    }
};