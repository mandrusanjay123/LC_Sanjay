class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        vector<int>ones_idxes;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1)ones_idxes.push_back(i);
        }
        // for(int n:ones_idxes)cout<<n<<endl;
        for(int i=1;i<ones_idxes.size();i++){
            if(ones_idxes[i]-ones_idxes[i-1]-1<k)return false;
        }
        return true;
    }
};