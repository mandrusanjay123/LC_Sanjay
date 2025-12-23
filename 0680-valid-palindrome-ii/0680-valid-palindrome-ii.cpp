class Solution {
public:
    bool validPalindrome(string s) {
        int i=0;
        int n=s.length();
        int j=n-1;
        bool used=false;
        while(i<=j){
            if(s[i]!=s[j]&&!used){
                used=true;
                //i++
                bool firstFail=false;
                int tempI=i;
                int tempJ=j;
                i++;
                while(i<=j){
                    if(s[i]!=s[j]){
                        firstFail=true;
                        break;
                    }
                    i++;
                    j--;
                }
                //or
                //j--;
                if(firstFail){
                    tempJ--;
                    while(tempI<=tempJ){
                        if(s[tempI]!=s[tempJ])return false;
                        tempI++;
                        tempJ--;
                    }
                    i=tempI;
                    j=tempJ;
                }
            }
            else if(s[i]!=s[j]&&used){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};