class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element=0;
        bool election=false;
        int vote=0;
        for(int i=0;i<nums.size();i++){
            if(election&&nums[i]==element){
                vote++;
            }
            if(!election){
                element=nums[i];
                election= true;
                vote=1;
            }
            if(nums[i]!=element){
                vote--;
            }
            if(vote==0){
                election =false;
            }
        }
        // cout<<vote;
        return element;
    }
};