class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int min_score=INT_MAX;
        int i=0;
        int n=nums.size();
        while(i<n&&i+k-1<n){
            min_score=min((nums[i+k-1]-nums[i]),min_score);
            i++;
        }
        return min_score;
    }
};