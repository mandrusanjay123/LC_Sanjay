class Solution {
public:
    int maxOperations(string s) {
        int num_ones=0;
        // int zero_beforeone=0;
        int total_moves=0;
        for(int i=0;i<s.length();i++){
            int num=s[i]-'0';
            if(num==1)num_ones++;
            else if(i+1<s.length()&&num==0&&s[i+1]=='1'){
                total_moves+=num_ones;

            }
            }
            if(s[s.length()-1]=='0'){
                total_moves+=num_ones;
            }
        return total_moves;
    }
};