class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int max_freq=0;
        int count=0;
        for(auto itr=mp.begin();itr!=mp.end();itr++){
            if(itr->second>max_freq){
                max_freq=itr->second;
                count=1;
                continue;
            }
            else if(itr->second==max_freq){
                count++;
            } 
        }
        return count*max_freq;
    }
};