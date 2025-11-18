class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n=bits.size();
        if(bits[n-1]!=0)return false;
        int i=0;
        vector<int>v;
        while(i<n){
            if(bits[i]==0){
                v.push_back(1);
                i+=1;
            }
            else{
                v.push_back(2);
                i+=2;
            }
        }
        if(v.back()==1)return true;
        return false;
    }
};