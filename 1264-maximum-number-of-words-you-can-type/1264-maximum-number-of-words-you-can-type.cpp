class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int count=0;
        int letters[26]={0};
        for(char c:brokenLetters ){
            letters[c-'a']++;
        }
        bool notbroken=true;
        for(int i=0;i<text.length();i++){
           while(i<text.length()&&text[i]!=' '){
            if(letters[text[i]-'a']){
                notbroken=false;
            }
            i++;
           }
           if(notbroken)count++;
           notbroken=true;
        }
        return count;
    }
};