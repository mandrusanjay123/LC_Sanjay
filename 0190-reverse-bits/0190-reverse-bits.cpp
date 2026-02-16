class Solution {
public:
    int reverseBits(int n) {
        int ans=0;
        int range=32;
        while(range>0){
            if(n&1){
                ans=ans*2+1;
            }
            else{
                ans=ans*2;
            }
            n>>=1;
            range--;
        }
        return ans;
    }
};