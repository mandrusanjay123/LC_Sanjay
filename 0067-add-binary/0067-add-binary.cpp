class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.length();
        int m = b.length();
        int i = n-1;
        int j = m-1;
        int carry = 0; 
        string ans = "";
        while( i >= 0 && j >= 0 ){
            if(a[i]=='1' && b[j] == '1'){
                if(carry){
                    ans+='1';
                }
                else{
                    carry=1;
                    ans+='0';
                }
                
            }
            else if(a[i]== '1' || b[j] == '1'){
                if(carry) {
                    ans+='0';
                }
                else{
                    ans+='1';
                }
            }
            else{
                if(carry){
                    ans+='1';
                    carry=0;
                }
                else{
                    ans+='0';
                }
            }
            i--;
            j--;
        }

        while(i>=0){
            if(a[i]=='1'){
                if(carry == 1){
                    ans+= '0';
                }
                else{
                    ans+= '1';
                }
            }
            else{
                if(carry ==1){
                    ans+='1';
                    carry=0;
                }
                else{
                    ans+='0';
                }
            }
            i--;
        }
          while(j>=0){
            if(b[j]=='1'){
                if(carry == 1){
                    ans+= '0';
                }
                else{
                    ans+= '1';
                }
            }
            else{
                if(carry ==1){
                    ans+='1';
                    carry=0;
                }
                else{
                    ans+='0';
                }
            }
            j--;
        }
        if(carry)ans+='1';
        reverse(ans.begin(),ans.end());
        return ans;
    }
};