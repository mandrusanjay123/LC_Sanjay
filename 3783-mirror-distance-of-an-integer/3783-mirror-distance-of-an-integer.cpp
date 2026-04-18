class Solution {
public:
    int mirrorDistance(int n) {
        int rnum=0;
        int temp=n;

        while(n>=1){
            rnum= rnum*10 + n%10;
            n/=10;
        }

        return abs(rnum-temp);
    }
};