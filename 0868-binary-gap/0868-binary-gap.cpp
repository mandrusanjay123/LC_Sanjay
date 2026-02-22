class Solution {
public:
    int binaryGap(int n) {
        string bits="";
        int max_len=0;
        int prev=-1;
        int i=0;
        while(n>0){
            if(n&1){
                if(prev==-1)prev=i;
                else {
                    max_len=max(max_len,abs(prev-i));
                    prev=i;
                }
            }
            n>>=1;
            i++;
        }
        return max_len;
    }
};