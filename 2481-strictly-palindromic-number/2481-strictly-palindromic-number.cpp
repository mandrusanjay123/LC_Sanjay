class Solution {
public:
    bool ispalindrome(string s){
        int left=0;
        int right=s.length()-1;
        while(left<=right){
            if(s[left]!=s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    string givestringfor(int base,int n){
        int rem=0;
        // int q=0;
        string s="";
        while(n>0){
            rem=n%base;
            n=n/base;
            s+=rem;
        }
        return s;
    }
    bool isStrictlyPalindromic(int n) {
        for(int base=2;base<=n-2;base++){
        string s=givestringfor(base,n);
        // cout<<s<<endl;
        if(!ispalindrome(s))return false;
        }
        return true;
        
    }
};