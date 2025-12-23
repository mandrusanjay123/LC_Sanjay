class Solution {
public:
    bool isPalindrome(string s) {
        int i=0;
        int j=s.length()-1;
        while(i<=j){
            char left_char=s[i];
            char right_char=s[j];
            cout<<left_char<<" "<<right_char<<endl;
            if(i<s.length()&&!isalpha(left_char)&&!isdigit(left_char)){
                i++;
                continue;
            }
            if(j>=0&&!isalpha(right_char)&&!isdigit(right_char)){
                j--;
                continue;
            }
            if(tolower(left_char)!=tolower(right_char)){
                return false;
            }
            i++;
            j--;
            
        }
        return true;
    }
};