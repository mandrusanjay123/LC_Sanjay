class Solution {
public:
    bool hasAlternatingBits(int n) {
        // int bit1=-1;
        // int bit2=-1;
        string bits="";
        while(n>0){
            if(n&1)bits+='1';
            else bits+='0';
            n>>=1;
        }
        if(bits.length()<2)return true;
        int j=1;
        int i=0;
        while(j<bits.length()){
            if(bits[j++]==bits[i++])
            return false;
        }
         return true;
            
        }
};