class Solution {
public:
    int maxFreqSum(string s) {
        int max_freq_cons=0;
        int max_freqvow=0;
        int freq[26]={0};
        for(int i=-0;i<s.length();i++){
            freq[s[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(i==0||i==4||i==8||i==14||i==20){
                max_freqvow=max(max_freqvow,freq[i]);
            }
            else{
                max_freq_cons=max(max_freq_cons,freq[i]);
            }
        }
        return max_freq_cons+max_freqvow;
    }
};