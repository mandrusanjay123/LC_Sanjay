class Solution {
public:
    bool isvowel(char c){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')return true;
        return false;
    }
    string reverseVowels(string s) {
        string vowels="";
        for(int i=0;i<s.length();i++){
            if(isvowel(tolower(s[i]))){
                vowels+=s[i];
            }
        }
        int n=vowels.size()-1;
        for(int i=0;i<s.length();i++){
            if(isvowel(tolower(s[i]))){
                s[i]=vowels[n--];
            }
        }
        return s;
    }
};