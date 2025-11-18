class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n=bits.size();
        if(bits[n-1]!=0)return false;
        int i=0;
        int prev=0;
        while(i<n){
            if(bits[i]==0){
                prev=1;
                i+=1;
            }
            else{
                prev=2;
                i+=2;
            }
        }
        if(prev==1)return true;
        return false;
    }
};