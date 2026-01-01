class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=0;
        for(int i=digits.size()-1;i>=0;i--){
            if(i==0&&digits[i]+1>9){
                carry=1;
            }
            if(digits[i]+1>9){
                digits[i]=(digits[i]+1)%10;
                continue;
            }
            else{
                digits[i]+=1;
                break;
            }
        }
        if(!carry)return digits;
        vector<int>ans;
        ans.push_back(1);
        for(int i=0;i<digits.size();i++)ans.push_back(digits[i]);
        return ans;
    }
};