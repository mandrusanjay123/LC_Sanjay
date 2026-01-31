class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {

        for(int i=0;i<letters.size();i++){
            while(i<letters.size()&&letters[i]==target){
                i++;
            }
            if(i+1<letters.size()&&letters[i]==target)return letters[i+1];
            if(i<letters.size()&&letters[i]>target){
                return letters[i];
            }
        }
        return letters[0];

    }
};