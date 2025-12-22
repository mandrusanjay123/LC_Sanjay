class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        //if two prefix sums are equal then the length between those indeces is wht I need
        //Ill take 0 as -1 and 1 a 1
        //so if i have equal no of 1's and 0's means I have sum always zero
        //I'll keep trac k of this max_len updating whenever i have the sum as 0
        int sum=0;
        int max_len=0;
        unordered_map<int,int>prefixsum_to_index;
        prefixsum_to_index[0]=-1;
        for(int i=0;i<nums.size();i++){
            sum+=(nums[i]==0)?-1:1;
            if(prefixsum_to_index.find(sum)==prefixsum_to_index.end()){
                prefixsum_to_index[sum]=i;
            }
            else{
                max_len=max(max_len,(i-prefixsum_to_index[sum]));
            }
        }
        return max_len;
    }
};