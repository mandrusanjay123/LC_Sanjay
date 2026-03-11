class Solution {
public:
    int bitwiseComplement(int n) {
        string bits="";
        int num=0;
        if(n==0)return 1;
        while(n>=1){
            if(n%2==0){
                bits+='1';
                // num=num*2+1;
            }
            else{
                bits+='0';
            }
            n>>=1;
        }

        for(int i=bits.size()-1;i>=0;i--){
            num=num*2+(bits[i]-'0');
        }
        // cout<<bits;
        return num;
    }
};