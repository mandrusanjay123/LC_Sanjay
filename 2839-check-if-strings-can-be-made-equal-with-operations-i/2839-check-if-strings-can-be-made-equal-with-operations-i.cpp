class Solution {
public:
    bool check(string &s1,string &s2){
        for(int i=0;i<4;i++){
            if(s1[i]!=s2[i])return false;
        }
        return true;
    }
    bool recursion(string &s1,string &s2,int i,int j){
        if(j==4){
            return check(s1,s2);
        }
        if(recursion(s1,s2,i+1,j+1))return true;
        swap(s1[i],s1[j]);
        if(recursion(s1,s2,i+1,j+1))return true;
        swap(s1[i],s1[j]);
        return false;
    }
    bool canBeEqual(string s1, string s2) {
        int i=0;
        int j=2;
        return recursion(s1,s2,i,j);
    }
};