class Solution {
public:
    bool hasSameDigits(string s) {
        if(s.length()==2){
            if(s[0]==s[1])return true;
            else return false;
        }
        string temp="";
        for(int i=1;i<s.length();i++){
            temp+=((int)(s[i]-'0')+(int)(s[i-1]-'0'))%10;
        }
        return hasSameDigits(temp);
    }
};