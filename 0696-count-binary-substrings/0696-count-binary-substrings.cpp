class Solution {
public:
    int countBinarySubstrings(string s) {
        int strk=1;
        int prev=0;
        int res=0;
        for (int i = 1; i < s.length(); i++) {
    if (s[i] == s[i-1] ){
        strk++; 
                     // still in the same group
                             // extend current streak
    } else {
        prev = strk;         // group changed, store length
        strk = 1;            // reset
    }

    // *
    if (strk <= prev)
        res++;
}

return res;
    }
};