class Solution {
public:
    int lengthOfLastWord(string s) {
        bool word=false;
        int lastIdx=-1;
        int emptySpace=0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]==' '){
                if(word)
                {   lastIdx=i;
                    break;
                }
                emptySpace++;
            }
            else{
                word=true;
            }
        }
        // if(lastIdx==-1)return s.length();
        return (s.length()-1-lastIdx-emptySpace);
    }
};