class Solution {
public:
    int mirrorDistance(int n) {
        int rnum=0;
        int temp=n;

        int rem = 0;

        while(n>=1){
            rem= n%10;
            rnum= rnum*10 + rem;
            n/=10;
        }

        return abs(rnum-temp);
    }
};