class Solution {
public:
    string largestGoodInteger(string nums) {
        string ans="";
        string max_ans="";
        int n=nums.size();
        int size=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                size++;
                ans+=nums[i-1];
            }
            else{
                size=1;
                ans="";
            }
            if(size==3){
                ans+=nums[i-1];
                max_ans=max(max_ans,ans);
            }
          
        }
        // if(size==3&&nums[n-3]==nums[n-2]&&nums[n-2]==nums[n-1]){
        //     ans+=nums[n-1];
        //     max_ans=max(max_ans,ans);
        // }
        return max_ans;
    }
};