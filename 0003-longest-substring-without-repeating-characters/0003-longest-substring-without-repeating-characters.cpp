class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len=0;
        if(s.length()==0)return 0;
        vector<int> freq(256, 0);
        int slow;
        int fast=0;
        for(fast=0;fast<s.length();fast++){
            freq[s[fast]]++;
            while(freq[s[fast]]>1){
                freq[s[slow]]--;
                slow++;
            }
            max_len=max(max_len,fast-slow+1);
        }
        return max_len;
    }
};