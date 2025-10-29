class Solution {
public:
    int smallestNumber(int n) {
        int x=0;
        while(x<n){
            x=x*2+1;
        }
        return x;
    }
};