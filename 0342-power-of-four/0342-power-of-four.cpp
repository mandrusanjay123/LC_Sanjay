class Solution {
public:
    bool isPowerOfFour(int n) {
        int reminder=0;
        while(n>1){
            if(reminder!=0)return false;
            reminder=n%4;
            n/=4;
        }
        if(reminder||n!=1)return false;
        return true;
    }
};