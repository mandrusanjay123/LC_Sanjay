class Solution {
public:
    int reverseBits(int n) {
        int ans=0;
        // string bits="";
        int range=32;
        while(range>0){
            if(n&1){
                // bits+='1';
                ans=ans*2+1;
            }
            else{
                // bits+='0';
                ans=ans*2;
            }
            n>>=1;
            range--;
        }
        // cout<<bits;
        return ans;
    }
};