class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0;
        int cnt2=0;
        int elem1=0;
        int elem2=0;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(cnt1==0&&elem2!=nums[i]){
                elem1=nums[i];
                cnt1=1;
            }
            else if(cnt2==0&&elem1!=nums[i]){
                elem2=nums[i];
                cnt2=1;
            }
            else if(elem1==nums[i]){
                cnt1++;
            }
            else if(elem2==nums[i]){
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0;
        cnt2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==elem1){
                cnt1++;
            }
            if(nums[i]==elem2){
                cnt2++;
            }
        } 
        cout<<elem1<<","<<elem2;
        if(elem1==elem2){
            ans.push_back(elem1);
            return ans;
        }
        if(cnt1>nums.size()/3)ans.push_back(elem1);
        if(cnt2>nums.size()/3)ans.push_back(elem2);
        sort(ans.begin(),ans.end());
        return ans;
    }
};