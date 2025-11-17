class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        vector<int>ones_idxes;
        int lastOneIdx=0;
        while(lastOneIdx<nums.size()&&nums[lastOneIdx]!=1){
            lastOneIdx++;
        }
        for(int i=lastOneIdx+1;i<nums.size();i++){
           if(nums[i]==1){
            if(i-lastOneIdx-1<k){
                return false;
            }
            lastOneIdx=i;
           }
        }
        return true;
    }
};