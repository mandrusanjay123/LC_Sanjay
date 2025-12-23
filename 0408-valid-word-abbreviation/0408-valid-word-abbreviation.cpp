class Solution {
public:
    bool validWordAbbreviation(string word, string s) {
        bool firstDigit=true;
        int len=0;
        for(int i=0;i<s.length();i++){
            if(isdigit(s[i])){
                if(s[i]-'0'==0&&firstDigit)return false;
                firstDigit=false;
                int num=0;
                while(i<s.length()&&isdigit(s[i])){
                num=num*10+(s[i]-'0');
                i++;
                }
                // cout<<num<<endl;
                len+=num;
            }
            firstDigit=true;
            if(i<s.length()){
                if(len<word.length())if(s[i]!=word[len])return false;
                len++;
            }
        }
        // cout<<len<<endl;
        if(len==word.length())return true;
        return false;
    }
};