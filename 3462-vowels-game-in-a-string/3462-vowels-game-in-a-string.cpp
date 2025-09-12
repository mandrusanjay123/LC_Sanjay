class Solution {
public:
bool isvowel(char c){
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')return true;
    return false;
}
    bool doesAliceWin(string s) {
        int freq=0;
        for(int i=0;i<s.length();i++){
            if(isvowel(s[i])){
                freq++;
            }
        }
        if(freq==0)return false;
        return true;
    }
};